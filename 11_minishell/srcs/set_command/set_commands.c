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
	while (children--)
	{
		close(fd[0][1]);
		pid = wait(&wstatus);
		pid = find_pid(pid, pidarr, count);
		if (pid + 1 < count)
			close(fd[pid + 1][FOR_WRITE]);
	}
}

static int	make_process(t_commands *commands)
{
	int		*pid;
	int		i;

	pid = malloc(sizeof(int) * commands->pipe_num);
	i = -1;
	while (++i < commands->pipe_num)
	{
		pid[i] = fork();
		if (pid[i] == CHILD)
		{
			errno = 0;
			dup_fd(&commands[i]);
			if (errno == 0)
				run_commands(&commands[i]);
			return (CHILD);
		}
	}
	wait_for_child(i, pid, commands->fd);
	free(pid);
	return (PARENTS);
}

int	set_commands(t_commands *commands)
{
	if (commands->pipe_num > 1 || is_nonbuilt(commands->com))
		return (make_process(commands));
	else
		run_commands(commands);
	return (PARENTS);
}
