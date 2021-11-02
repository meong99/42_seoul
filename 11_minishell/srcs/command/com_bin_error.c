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
	write(2, "minishell: ", 11);
	write(2, com, ft_strlen(com));
	write(2, ": ", 2);
	write(2, err_msg, ft_strlen(err_msg));
	write(2, "\n", 1);
	exit(errno);
}
