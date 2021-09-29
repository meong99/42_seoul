#include "minishell.h"

void	exe_commands(t_commands *commands)
{
	char	*command;

	command = commands->com;
	if (ft_strncmp(command, "cd", 2) == 0)
		exe_cd(commands);
	else if (ft_strncmp(command, "pwd", 3) == 0)
		exe_pwd(commands);
	else if (ft_strncmp(command, "export", 6) == 0)
		exe_export(commands, commands->env);
	else if (ft_strncmp(command, "unset", 5) == 0)
	;
	else if (ft_strncmp(command, "env", 3) == 0)
	;
	else if (ft_strncmp(command, "exit", 4) == 0)
	;
	else
	;
}