#include "minishell.h"

void	redir_output(char *target)
{
	int	fd;

	fd = open(target, O_WRONLY | O_CREAT);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}
