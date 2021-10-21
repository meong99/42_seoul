#include "minishell.h"

void	redir_append(char *target)
{
	int		fd;

	fd = open(target, O_WRONLY | O_CREAT | O_APPEND, 0666);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}
