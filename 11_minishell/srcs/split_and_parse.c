#include "minishell.h"

void	split_space(char *str, t_commands *commands)
{
	char	**result;
	int		i;

	i = -1;
	result = ft_split_f(str, ' ', inside_quote);
	while (result[++i])
	{
		if (ft_strnstr("<<><>>", result[i], 4))
			ft_lstadd_back(&commands->redirections, \
				ft_lstnew(ft_strdup(result[i])));
		else if (i > 0 && ft_strnstr("<<><>>", result[i - 1], 4))
			ft_lstadd_back(&commands->filename, \
				ft_lstnew(ft_strdup(result[i])));
		else if (commands->com == NULL)
			commands->com = ft_strdup(result[i]);
		else
			ft_lstadd_back(&commands->arg, ft_lstnew(ft_strdup(result[i])));
	}
	ft_free(result, 0, true);
}

t_commands	*split_pipe(char *str)
{
	char		**tmp;
	int			count_pipe;
	int			i;
	t_commands	*commands;

	i = -1;
	count_pipe = 0;
	tmp = ft_split_f(str, '|', inside_quote);
	while (tmp[count_pipe])
		count_pipe++;
	commands = malloc(sizeof(t_commands) * count_pipe);
	while (++i < count_pipe)
	{
		init_commands(&commands[i]);
		split_space(tmp[i], &commands[i]);
		commands[i].index = i;
		commands[i].count_pipe = count_pipe;
	}
	ft_free(tmp, 0, true);
	return (commands);
}
