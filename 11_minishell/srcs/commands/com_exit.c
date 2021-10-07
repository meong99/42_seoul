#include "minishell.h"

void	exe_exit(t_commands *commands)
{
	errno = ft_atoi((char *)commands->arg->content);
	exit(errno);
}
