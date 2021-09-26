#include "minishell.h"

void	run_c_process(t_commands *commands, t_fd *fd)
{
	char	*str;

	dup2(fd->fd_to_c[FOR_READ], STDIN_FILENO);
	// if (get_next_line(STDIN_FILENO, &str) == -1)
	// {
	// 	printf("gnl error\n");
	// 	exit(0);
	// }
	while ((str = readline("-")))
	{
		printf("child = %s\n", str);
	}
	commands = 0;
}