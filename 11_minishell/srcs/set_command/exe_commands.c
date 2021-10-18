#include "minishell.h"

static int	is_nonbuilt(char *com)
{
	if (ft_strncmp(com, "cd", 3) == 0)
		return (false);
	else if (ft_strncmp(com, "pwd", 4) == 0)
		return (false);
	else if (ft_strncmp(com, "export", 7) == 0)
		return (false);
	else if (ft_strncmp(com, "unset", 6) == 0)
		return (false);
	else if (ft_strncmp(com, "env", 4) == 0)
		return (false);
	else if (ft_strncmp(com, "exit", 5) == 0)
		return (false);
	else if (ft_strncmp(com, "echo", 5) == 0)
		return (false);
	else
		return (true);
}

static void	run_commands(t_commands *commands)
{
	char	*com;

	com = commands->com;
	if (ft_strncmp(com, "cd", 3) == 0)
		exe_cd(commands);
	else if (ft_strncmp(com, "pwd", 4) == 0)
		exe_pwd();
	else if (ft_strncmp(com, "export", 7) == 0)
		exe_export(commands);
	else if (ft_strncmp(com, "unset", 6) == 0)
		exe_unset(commands);
	else if (ft_strncmp(com, "env", 4) == 0)
		exe_env(commands);
	else if (ft_strncmp(com, "exit", 5) == 0)
		exe_exit(commands->arg);
	else if (ft_strncmp(com, "echo", 5) == 0)
		exe_echo(commands);
	else
		exe_bin(commands);
}

int	find_pid(int pid, int*pidarr, int count)
{
	while (count--)
	{
		if (pidarr[count] == pid)
			return (count);
	}
	return (0);
}
static int	make_process(t_commands *commands)
{
	int		*pid;
	int		wstatus;
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
	while (i--)
	{
		int	tmp;
		char *str = ft_strdup("");
		char buf[100];
		int count;
		tmp = wait(&wstatus);
		count = find_pid(tmp, pid, commands->count_pipe);
		close(commands->fd[count][FOR_WRITE]);
		while (1)
		{
			int a;
			a = read(commands->fd[count][FOR_READ], buf, 100);
			if (a == 0 || a == -1)
				break ;
			buf[a] = 0;
			str = ft_strjoin_free(str, buf);
		}
		write(commands->fd[count + 1][FOR_WRITE], str, ft_strlen(str));
		close(commands->fd[count + 1][FOR_WRITE]);
		free(str);
	}
	free(pid);
	return (PARENTS);
}

int	exe_commands(t_commands *commands)
{
	if (commands->count_pipe > 1 || is_nonbuilt(commands->com))
		return (make_process(commands));
	else
		run_commands(commands);
	return (PARENTS);
}
