/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:47:11 by mchae             #+#    #+#             */
/*   Updated: 2021/11/26 01:52:41 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	dup_input(t_commands *commands)
{
	int		*fd;

	fd = commands->fd[commands->index];
	if (commands->index != 0)
		dup2(fd[FOR_READ], STDIN_FILENO);
	close(fd[FOR_READ]);
	close(fd[FOR_WRITE]);
}

static void	dup_output(t_commands *commands)
{
	int		*fd;

	fd = commands->fd[commands->index + 1];
	dup2(fd[FOR_WRITE], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
}

static void	handle_redir_in(t_commands *commands)
{
	int		*fd;
	char	*redir_str;

	redir_str = commands->redir_input;
	fd = commands->fd[commands->index];
	dup2(fd[FOR_READ], STDIN_FILENO);
	ft_putstr_fd(redir_str, fd[FOR_WRITE]);
	close(fd[FOR_READ]);
	close(fd[FOR_WRITE]);
}

static void	handle_redir_out(t_commands *commands)
{
	if (ft_strncmp(">>", commands->redir_out, 3) == 0)
		redir_append(commands->redir_out_file);
	else
		redir_output(commands->redir_out_file);
}

void	dup_fd(t_commands *commands)
{
	int	i;

	if (commands->redir_input)
		handle_redir_in(commands);
	else
		dup_input(commands);
	if (commands->redir_out_file)
		handle_redir_out(commands);
	else if (commands->index + 1 != commands->command_num)
		dup_output(commands);
	i = -1;
	while (++i < commands->index)
		close(commands->fd[i][FOR_WRITE]);
}
