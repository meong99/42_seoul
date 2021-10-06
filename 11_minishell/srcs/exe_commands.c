#include "minishell.h"

void	exe_commands(t_commands *commands)
{
	char	*com;

	com = commands->com;
	if (ft_strncmp(com, "cd", 2) == 0)
		exe_cd(commands);
	else if (ft_strncmp(com, "pwd", 3) == 0)
		exe_pwd();
	else if (ft_strncmp(com, "export", 6) == 0)
		exe_export(commands);
	else if (ft_strncmp(com, "unset", 5) == 0)
		exe_unset(commands);
	else if (ft_strncmp(com, "env", 3) == 0)
	;
	else if (ft_strncmp(com, "exit", 4) == 0)
	;
	else
	;
}
