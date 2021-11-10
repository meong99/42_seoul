/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:47:13 by mchae             #+#    #+#             */
/*   Updated: 2021/11/10 22:48:02 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	find_pid(int pid, int*pidarr, int count)
{
	while (count--)
	{
		if (pidarr[count] == pid)
			return (count);
	}
	return (0);
}

static void	wait_for_child(int children, int *pidarr, int **fd)
{
	int		wstatus;
	int		count;
	int		pid;

	count = children;
	close(fd[0][0]);
	close(fd[0][1]);
	while (children--)
	{
		pid = wait(&wstatus);
		if (0 == (wstatus & 0xff))
			errno = wstatus >> 8;
		else
			errno = wstatus;
		pid = find_pid(pid, pidarr, count);
		if (pid + 1 < count)
			close(fd[pid + 1][FOR_WRITE]);
	}
}

static int	make_process(void)
{
	int		*pid;
	int		i;

	pid = malloc(sizeof(int) * g_commands->command_num);
	ft_protect(pid);
	i = -1;
	while (++i < g_commands->command_num)
	{
		g_commands[i].sig_handle = false;
		put_sigint();
		pid[i] = fork();
		if (pid[i] == CHILD)
		{
			errno = 0;
			dup_fd(&g_commands[i]);
			if (errno == 0)
				run_commands(&g_commands[i]);
			return (CHILD);
		}
		else if (pid[i] == -1)
			ft_protect(NULL);
	}
	ignore_sigint();
	wait_for_child(i, pid, g_commands->fd);
	free(pid);
	return (PARENTS);
}

static int	builtin_redirset(void)
{
	char	*filename;
	int		old_stdout;
	
	filename = g_commands->redir_out_file;
	old_stdout = dup(STDOUT_FILENO);
	if (ft_strncmp(g_commands->redir_out, "<<", 3) == 0)
		redir_append(filename);
	else
		redir_output(filename);
	return (old_stdout);
}

int	set_commands(void)
{
	int	redir;
	int	old_stdout;

	redir = false;
	if (g_commands->command_num > 1 || is_nonbuilt(g_commands->com))
		return (make_process());
	else
	{
		if (g_commands->redir_out)
		{
			old_stdout = builtin_redirset();
			redir = true;
		}
		run_commands(g_commands);
		if (redir == true)
			dup2(old_stdout, STDOUT_FILENO);
	}
	return (PARENTS);
}
