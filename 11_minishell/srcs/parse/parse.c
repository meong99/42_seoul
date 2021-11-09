/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:46:49 by mchae             #+#    #+#             */
/*   Updated: 2021/11/09 21:13:14 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	make_file(char *filename, int option)
{
	int		fd;

	fd = open(filename, O_WRONLY | O_CREAT | option, 0644);
	if (fd == -1)
	{
		put_err(filename, false);
		if (errno == 2)
			errno = 1;
	}
	close(fd);
	return ;
}

static void	parse_commands(char **spl_pipe)
{
	int		i;
	char	*except_redir;

	i = -1;
	while (spl_pipe[++i])
	{
		if (!errno)
			except_redir = redir_handler(&g_commands[i], spl_pipe[i]);
		if (!errno)
			parse_space(&g_commands[i], except_redir);
		free(except_redir);
		if (errno)
			break ;
	}
	ft_free(spl_pipe, 0, true);
}

static void	makepipe(void)
{
	int	**fd;
	int	i;

	fd = malloc(sizeof(int *) * g_commands->command_num);
	ft_protect(fd);
	i = -1;
	while (++i < g_commands->command_num)
	{
		fd[i] = malloc(sizeof(int) * 2);
		ft_protect(fd[i]);
		if (pipe(fd[i]) == -1)
			put_err("pipe", true);
		g_commands[i].fd = fd;
	}
}

void	parsing_handler(char *str, int old_errno, t_env *env)
{
	char		**spl_pipe;
	int			i;

	i = -1;
	spl_pipe = ft_split_f(str, '|', BOTH, check_quote);
	ft_protect(spl_pipe);
	parse_pipe(spl_pipe);
	g_commands->old_errno = old_errno;
	while (++i < g_commands->command_num)
		init_commands(&g_commands[i], env);
	makepipe();
	parse_commands(spl_pipe);
}
