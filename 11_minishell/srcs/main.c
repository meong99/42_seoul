#include "minishell.h"
void	arg(void *str);
void	re(void *str);
void	file(void *str);
void	del(void *str);
void	delete(void *str);

int		main(void)
{
	t_commands	*commands;
	char		*str;

	while (1)
	{
		str = readline("minishell >");
		if (str == NULL)
			exit(0);
		add_history(str);
		commands = split_pipe(str);

		for (int i = 0; i < commands[i].total_index; i++)
		{
			printf("com=%s ", commands[i].com);
			ft_lstiter(commands->arg, arg);
			ft_lstiter(commands->redirections, re);
			ft_lstiter(commands->filename, file);
			ft_lstiter(commands->delimiter, del);
			printf("\n");
		}
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
