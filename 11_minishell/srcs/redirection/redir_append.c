#include "minishell.h"

void	redir_append(char *filename)
{
	int		fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}
