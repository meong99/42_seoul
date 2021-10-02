#include "minishell.h"

int	**make_pipe(t_commands *commands)
{
	int	**fd;
	int	i;

	i = -1;
	fd = malloc(sizeof(int *) * (commands->count_pipe - 1));
	while (++i < commands->count_pipe - 1)
	{
		fd[i] = malloc(sizeof(int) * 2);
		if (pipe(fd[i]) == RET_ERR_INT)
		{
			printf("error occurred when sending value to child process\n");
			exit(errno);
		}
	}
	return (fd);
}
