#include "minishell.h"
void	arg(void *str);
void	re(void *str);
void	file(void *str);
void	del(void *str);
void	delete(void *str);

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
		pipe(fd);
		str = readline("minishell >");
		if (str == NULL)
			exit(0);
		if (*str)
			add_history(str);
		commands = split_pipe(str);
		fd = malloc(sizeof(int *) * commands->count_pipe);
		for (int i = 0; i < commands->count_pipe; i++)
		{
			fd[i] = malloc(sizeof(int) * 2);
			pipe(fd[i]);
			commands[i].fd = fd[i];
		}
		exe_commands(commands);
		free(commands->com);
		ft_lstclear(&commands->arg, delete);
		ft_lstclear(&commands->redirections, delete);
		ft_lstclear(&commands->filename, delete);
		// free(commands);
		free(str);
	}

	// make_pipe(&fd);
	// while (true)
	// {
	// 	run_p_process(&commands, &fd);
	// }
	return (0);
}
