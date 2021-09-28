#include "minishell.h"

void	exit_if_ret_err()
{
	
}

void	print_err(int err_code)
{
	char	*str;

	str = strerror(err_code);
	printf("minishell: %s\n", str);
}