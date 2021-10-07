#include "minishell.h"

void	check_bin_error(char *com)
{
	char	*err_msg;

	if (ft_strchr(com, '/') == NULL)
		err_msg = "command not found";
	else
		err_msg = "No such file or directory";
	errno = 127;
	printf("minishell: %s: %s\n", com, err_msg);
	exit(errno);
}
