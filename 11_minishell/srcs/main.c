#include "minishell.h"

static int	check_errno(t_commands *commands, char **str)
{
	if (errno)
	{
		free_all(commands, str, commands->fd);
		return (1);
	}
	return (0);
}

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

static int	str_handler(char *str)
{
	if (str == NULL)
		exit(0);
	if (*str)
		add_history(str);
	if (*str == 0)
	{
		free(str);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_commands	*commands;
	struct termios	old_term;
	char		*str;

	ac = 0;
	av = 0;
	init_env_var(envp);
	terminal_handler(&old_term);
	signal(SIGINT, sig_handler);
	while (1)
	{
		str = readline("minishell> ");
		if (str_handler(str))
			continue ;
		commands = parsing_handler(str);
		makepipe(commands);
		if (check_errno(commands, &str))
			continue ;
		if (set_commands(commands) == CHILD)
			break ;
		free_all(commands, &str, commands->fd);
	}
	return (0);
}
