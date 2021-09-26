#include "minishell.h"

void	arg(void *str)
{
	if (str == NULL)
		return ;
	printf("arg=%s ", (char*)str);
}
void	re(void *str)
{
	if (str == NULL)
		return ;
	printf("re=%s ", (char*)str);
}
void	file(void *str)
{
	if (str == NULL)
		return ;
	printf("file=%s ", (char*)str);
}
void	del(void *str)
{
	if (str == NULL)
		return ;
	printf("del=%s ", (char*)str);
}

void	delete(void *str)
{
	free(str);
}

int		main(void)
{
	t_commands	*commands;
	char		*str;

	while (1)
	{
		str = readline("minishell >");
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
	}

	// make_pipe(&fd);
	// while (true)
	// {
	// 	run_p_process(&commands, &fd);
	// }
	return (0);
}
