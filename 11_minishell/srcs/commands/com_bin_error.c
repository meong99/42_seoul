#include "minishell.h"

void	check_bin_error(char *com)
{
	char	*err_msg;

	err_msg = "command not found";
	errno = 127;
	printf("minishell: %s: %s\n", com, err_msg);
	exit(errno);
}
