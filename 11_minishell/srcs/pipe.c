#include "minishell.h"

void	make_pipe(int fd_for_c[2], int fd_for_p[2])
{
	if (pipe(fd_for_c) == RET_ERR_INT)
	{
		printf("child pipe error\n");
		exit(errno);
	}
	if (pipe(fd_for_p) == RET_ERR_INT)
	{
		printf("parent pipe error\n");
		exit(errno);
	}
}