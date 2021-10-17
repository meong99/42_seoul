#include "minishell.h"

static void	parse_redir_in(char **result, t_commands *commands)
{
	char	*redir_mark;
	char	*filename;
	t_list	*redir_in;
	t_list	*redir_file;

	redir_mark = *result++;
	filename = *result;
	redir_in = commands->redir_in;
	redir_file = commands->filename_in;
	ft_lstadd_back(&redir_in, ft_lstnew(ft_strdup(redir_mark)));
	ft_lstadd_back(&redir_file, ft_lstnew(ft_strdup(filename)));
}

static void	parse_redir_out(char **result, t_commands *commands)
{
	char	*redir_mark;
	char	*filename;
	t_list	*redir_out;
	t_list	*redir_file;

	redir_mark = *result++;
	filename = *result;
	redir_out = commands->redir_out;
	redir_file = commands->filename_out;
	ft_lstadd_back(&redir_out, ft_lstnew(ft_strdup(redir_mark)));
	ft_lstadd_back(&redir_file, ft_lstnew(ft_strdup(filename)));
}

static void	split_space(char *str, t_commands *commands)
{
	char	**result;
	int		i;

	i = -1;
	result = ft_split_f(str, ' ', inside_quote);
	while (result[++i])
	{
		if (ft_strnstr("<<", result[i], 3))
			parse_redir_in(result + i, commands);
		else if (ft_strnstr(">>", result[i], 3))
			parse_redir_out(result + i, commands);
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
