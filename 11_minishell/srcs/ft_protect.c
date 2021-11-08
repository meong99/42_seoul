#include "minishell.h"

void	ft_protect(void *arg)
{
	if (arg == NULL && errno)
	{
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		exit(errno);
	}
}
