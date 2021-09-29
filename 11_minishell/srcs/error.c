#include "minishell.h"

void	exit_if_ret_err()
{
	
}

void	print_err(int err_code)
{
	char	*str;

	if (err_code == 0)
		return ;
	str = strerror(errno);
	printf("minishell: %s\n", str);
	free(str);
}