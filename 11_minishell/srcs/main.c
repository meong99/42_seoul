#include "minishell.h"

static void	makepipe(t_commands *commands)
{
	int			**fd;

	fd = malloc(sizeof(int *) * commands->pipe_num);
	for (int i = 0; i < commands->pipe_num; i++)
	{
		fd[i] = malloc(sizeof(int) * 2);
		pipe(fd[i]);
		commands[i].fd = fd;
	}
}

int		main(int ac, char **av, char **envp)
{
	t_commands	*commands;
	char		*str;

	ac = 0;
	av = 0;
	init_env_var(envp);
	while (1)
	{
		str = readline("minishell> ");
		if (str == NULL)
			exit(0);
		if (*str)
			add_history(str);
		commands = parsing_handler(str);
		makepipe(commands);
		if (errno)
		{
			printf("err\n");
			free_all(commands, &str, commands->fd);
			continue ;
		}
		if (set_commands(commands) == CHILD)
			return (0);
		free_all(commands, &str, commands->fd);
	}
	return (0);
}
