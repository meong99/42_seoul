#include "minishell.h"

int	print_systax_err(char *token)
{
	printf("minishell: syntax error near unexpected token `%s'\n", token);
	errno = 258;
	return (RET_ERR_INT);
}
