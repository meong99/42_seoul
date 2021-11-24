/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:47:13 by mchae             #+#    #+#             */
/*   Updated: 2021/11/24 18:35:01 by mchae            ###   ########.fr       */
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
	g_sig_handler[0] = SIG_USUAL;
}

static int	make_process(t_commands *commands)
{
	int		*pid;
	int		i;

	pid = malloc(sizeof(int) * commands->command_num);
	ft_protect(pid);
	i = -1;
	while (++i < commands->command_num)
	{
		commands[i].sig_handle = SIG_COM;
		put_sigint();
		pid[i] = fork();
		if (pid[i] == CHILD)
		{
			errno = 0;
			dup_fd(&commands[i]);
			if (errno == 0)
				run_commands(&commands[i]);
			return (CHILD);
		}
		ft_protect(NULL);
	}
	wait_for_child(i, pid, commands->fd);
	ignore_sigint();
	free(pid);
	return (PARENTS);
}

static int	builtin_redirset(t_commands *commands)
{
	char	*filename;
	int		old_stdout;

	filename = commands->redir_out_file;
	old_stdout = dup(STDOUT_FILENO);
	if (ft_strncmp(commands->redir_out, "<<", 3) == 0)
		redir_append(filename);
	else
		redir_output(filename);
	return (old_stdout);
}

int	set_commands(t_commands *commands)
{
	int	redir;
	int	old_stdout;

	redir = false;
	if (commands->command_num > 1 || is_nonbuilt(commands->com))
		return (make_process(commands));
	else
	{
		if (commands->redir_out)
		{
			old_stdout = builtin_redirset(commands);
			redir = true;
		}
		run_commands(commands);
		if (redir == true)
			dup2(old_stdout, STDOUT_FILENO);
	}
	return (PARENTS);
}
