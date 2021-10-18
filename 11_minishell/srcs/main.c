#include "minishell.h"

static void	delete(void *str)
{
	free(str);
}

static void	free_all(t_commands *commands, char *str, int **fd)
{
	free(commands->com);
	free(commands->redir_in);
	free(commands->redir_in_target);
	free(commands->redir_out);
	free(commands->redir_out_target);
	ft_lstclear(&commands->arg, delete);
	free(str);
	ft_free(fd, commands->count_pipe, false);
	free(commands);
}

int		main(int ac, char **av, char **envp)
{
	t_commands	*commands;
	char		*str;
	int			**fd;

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
		else if (*str == '\0')
			continue ;
		commands = split_pipe(str);
		fd = malloc(sizeof(int *) * commands->count_pipe);
		for (int i = 0; i < commands->count_pipe; i++)
		{
			fd[i] = malloc(sizeof(int) * 2);
			pipe(fd[i]);
			commands[i].fd = fd;
		}
		if (set_commands(commands) == CHILD)
			return (0);
		free_all(commands, str, fd);
	}
	return (0);
}
