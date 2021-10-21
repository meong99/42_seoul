#include "minishell.h"

void	redir_append(char *target)
{
	int		fd;

	fd = open(target, O_WRONLY | O_CREAT | O_APPEND | S_IRWXG);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}
