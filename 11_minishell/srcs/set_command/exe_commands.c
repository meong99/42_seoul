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
	waitpid(ALL_CHILD, &wstatus, 0);
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
