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

	ac = 0;
	av = 0;
	init_env(envp);
	while (1)
	{
		str = readline("minishell >");
		if (str == NULL)
			exit(0);
		add_history(str);
		commands = split_pipe(str);

		for (int i = 0; i < commands[i].count_pipe; i++)
		{
			printf("com=%s ", commands[i].com);
			ft_lstiter(commands->arg, arg);
			ft_lstiter(commands->redirections, re);
			ft_lstiter(commands->filename, file);
			ft_lstiter(commands->delimiter, del);
			printf("\n");
		}
		exe_commands(commands);
		free(commands->com);
		ft_lstclear(&commands->arg, delete);
		ft_lstclear(&commands->redirections, delete);
		ft_lstclear(&commands->filename, delete);
		ft_lstclear(&commands->delimiter, delete);
		free(str);
	}

	// make_pipe(&fd);
	// while (true)
	// {
	// 	run_p_process(&commands, &fd);
	// }
	return (0);
}
