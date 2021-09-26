#include "minishell.h"

void	make_pipe(t_fd *fd)
{
	int	*fd_to_c;
	int	*fd_to_p;

	fd_to_c = fd->fd_to_c;
	fd_to_p = fd->fd_to_p;
	if (pipe(fd_to_c) == RET_ERR_INT)
	{
		printf("error occurred when sending value to child process\n");
		exit(errno);
	}
	if (pipe(fd_to_p) == RET_ERR_INT)
	{
		printf("error occurred when sending value to parent process\n");
		exit(errno);
	}
}