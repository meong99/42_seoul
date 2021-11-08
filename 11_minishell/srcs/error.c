#include "minishell.h"

int	print_systax_err(char *token)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd("syntax error near unexpected token `", STDERR_FILENO);
	ft_putstr_fd(token, STDERR_FILENO);
	ft_putstr_fd("'\n", STDERR_FILENO);
	errno = 258;
	return (RET_ERR_INT);
}

void	put_err(char *fun_name)
{
	char	*str_err;

	str_err = strerror(errno);
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(fun_name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(str_err, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(errno);
}