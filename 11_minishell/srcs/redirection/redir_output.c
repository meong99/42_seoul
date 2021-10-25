#include "minishell.h"

void	redir_output(char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}
