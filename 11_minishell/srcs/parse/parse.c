/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:46:49 by mchae             #+#    #+#             */
/*   Updated: 2021/11/26 00:59:56 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	make_file(char *filename, t_commands *commands)
{
	int		fd;

	if (ft_strncmp(commands->redir_out, ">>", 3) == 0)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		put_err(filename, false);
		if (errno == 2)
			errno = 1;
	}
	close(fd);
	return ;
}

static void	parse_commands(t_commands *commands, char **spl_pipe)
{
	int		i;
	char	*except_redir;

	i = -1;
	while (spl_pipe[++i])
	{
		if (!errno)
			except_redir = redir_handler(&commands[i], spl_pipe[i]);
		if (!errno)
			parse_space(&commands[i], except_redir);
		free(except_redir);
		if (errno)
			break ;
	}
	ft_free(spl_pipe, 0, true);
}

static void	makepipe(t_commands *commands)
{
	int	**fd;
	int	i;

	fd = malloc(sizeof(int *) * commands->command_num);
	ft_protect(fd);
	i = -1;
	while (++i < commands->command_num)
	{
		fd[i] = malloc(sizeof(int) * 2);
		ft_protect(fd[i]);
		if (pipe(fd[i]) == -1)
			put_err("pipe", true);
		commands[i].fd = fd;
	}
}

t_commands	*parsing_handler(char *str, int old_errno, t_env *env)
{
	char		**spl_pipe;
	int			i;
	t_commands	*commands;

	i = -1;
	spl_pipe = ft_split_f(str, '|', BOTH, check_quote);
	ft_protect(spl_pipe);
	commands = parse_pipe(spl_pipe);
	commands->old_errno = old_errno;
	while (++i < commands->command_num)
		init_commands(&commands[i], env);
	makepipe(commands);
	parse_commands(commands, spl_pipe);
	return (commands);
}
