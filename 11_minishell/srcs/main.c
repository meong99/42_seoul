#include "minishell.h"
void	arg(void *str);
void	re(void *str);
void	file(void *str);
void	del(void *str);
void	delete(void *str);

static void	free_all(t_commands *commands, char *str, int **fd)
{
	free(commands->com);
	ft_lstclear(&commands->arg, delete);
	ft_lstclear(&commands->redirections, delete);
	ft_lstclear(&commands->filename, delete);
	free(str);
	ft_free(fd, commands->count_pipe + 1, false);
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
		str = readline("minishell >");
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
			commands[i].fd = fd[i];
		}
		exe_commands(commands);
		free_all(commands, str, fd);
		system("leaks minishell");
	}
	return (0);
}
