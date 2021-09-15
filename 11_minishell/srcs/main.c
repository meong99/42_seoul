#include "minishell.h"

int		main(void)
{
	int			pid;
	int			fd_for_c[2], fd_for_p[2];
	char		*str;
	t_commands	command;
	
	make_pipe(fd_for_c, fd_for_p);
	pid = fork();
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
