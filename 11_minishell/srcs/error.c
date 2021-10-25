#include "minishell.h"

int	print_systax_err(char *token)
{
	write(2, "minishell: ", 11);
	write(2, "syntax error near unexpected token `", 36);
	write(2, token, ft_strlen(token));
	write(2, "'\n", 2);
	errno = 258;
	return (RET_ERR_INT);
}
