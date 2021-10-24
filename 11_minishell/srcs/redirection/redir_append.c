#include "minishell.h"

void	redir_append(char *target)
{
	int		fd;

	if (*target == 0)
	{
		errno = 258;
		return ;
	}
	fd = open(target, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		//
		errno = 1;
		printf("bash: %s: Permission denied\n", target);
		return ;
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}
