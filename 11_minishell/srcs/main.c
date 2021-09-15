#include "minishell.h"

int		main(void)
{
	int			pid;
	int			fd_for_c[2], fd_for_p[2];
	char		*str;
	t_commands	command;
	
	init_all(&command);
	make_pipe(fd_for_c, fd_for_p);
	pid = fork();
	if (pid != C_PROCESS)
	{
		while (true)
		{
			str = readline("minishell >");
			add_history(str);
			split_and_parsing(str, &command);
			free(str);
		}
	}
}
