#include "minishell.h"

void	exe_commands(t_commands *commands)
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
