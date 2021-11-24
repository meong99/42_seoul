/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:47:22 by mchae             #+#    #+#             */
/*   Updated: 2021/11/24 17:32:29 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	guard_dangling(t_commands *commands)
{
	init_commands(commands, NULL);
	commands->index = 0;
	commands->command_num = 0;
}

static void	free_var(t_commands *commands)
{
	free(commands->com);
	ft_lstclear(&commands->arg, free);
	ft_lstclear(&commands->redir_lst_mark, free);
	ft_lstclear(&commands->redir_lst_target, free);
	free(commands->redir_in);
	free(commands->redir_input);
	free(commands->redir_out);
	free(commands->redir_out_file);
}

static void	close_fd(int **fd, int pipe_num)
{
	int	i;

	i = 0;
	free(fd[i]);
	while (++i < pipe_num)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		free(fd[i]);
	}
	free(fd);
}

void	free_all(t_commands *commands, char **str, int **fd)
{
	int	i;
	int	com_num;

	close_fd(fd, commands->command_num);
	i = -1;
	com_num = commands->command_num;
	while (++i < com_num)
	{
		free_var(&commands[i]);
		guard_dangling(&commands[i]);
	}
	free(*str);
	*str = 0;
	free(commands);
}
