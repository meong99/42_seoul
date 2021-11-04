#include "minishell.h"

void	ft_protect(void *arg)
{
	if (arg == NULL && errno)
	{
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		exit(errno);
	}
}
