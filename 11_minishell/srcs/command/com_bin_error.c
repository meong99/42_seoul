#include "minishell.h"

void	check_bin_error(char *com)
{
	char	*err_msg;
	if (com == NULL)
		return ;
	if (ft_strchr(com, '/'))
		err_msg = "No such file or directory";
	else
		err_msg = "command not found";
	errno = 127;
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(com, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(err_msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(errno);
}
