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

	count = children;
	while (children--)
	{
		int pid;
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

	pid = malloc(sizeof(int) * commands->count_pipe);
	i = -1;
	while (++i < commands->count_pipe)
	{
		pid[i] = fork();
		if (pid[i] == CHILD)
		{
			dup_fd(&commands[i]);
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
	if (commands->count_pipe > 1 || is_nonbuilt(commands->com))
		return (make_process(commands));
	else
		run_commands(commands);
	return (PARENTS);
}
