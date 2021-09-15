#include "minishell.h"

int		main(void)
{
	int			pid;
	int			fd[2];
	char		*str;
	t_commands	command;
	
	pid = 1;
	if (pipe(fd) == RET_ERR_INT)
	{
		printf("pipe error\n");
		exit(errno);
	}
	// pid = fork();
	// if (pid == RET_ERR_INT)
	// {
	// 	printf("fork error\n");
	// 	exit(errno);
	// }
	if (pid != C_PROCESS)
	{
		while (true)
		{
			str = readline("minishell >");
			add_history(str);
			command.arg = 0;
		}
	}
}
