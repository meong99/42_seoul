#include "minishell.h"

void	prt(void *str)
{
	printf("arg = %s ", (char*)str);
}

int		main(void)
{
	t_commands	*commands;
	char		*str;

	str = readline("minishell >");
	commands = split_pipe(str);

	for (int i = 0; i < commands[i].total_index; i++)
	{
		printf("com=%s ", commands[i].com);
		ft_lstiter(commands->arg, prt);
		printf("re=%s ", commands[i].redirections);
		printf("file=%s ", commands[i].filename);
		printf("del=%s ", commands[i].delimiter);
		printf("\n");
	}

	// make_pipe(&fd);
	// while (true)
	// {
	// 	run_p_process(&commands, &fd);
	// }
	return (0);
}
