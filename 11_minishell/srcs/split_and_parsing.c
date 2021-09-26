#include "minishell.h"

char	**split_before_char(char *str, char c)
{
	char	**result;
	char	*tmp;
	size_t	size;

	result = malloc(sizeof(char *) * 3);
	tmp = ft_strchr_f(str, c, inside_quote);
	size = tmp - str;
	result[0] = malloc(size + 1);
	result[1] = malloc(ft_strlen(tmp) + 1);
	ft_strlcpy(result[0], str, size + 1);
	ft_strlcpy(result[1], tmp, ft_strlen(tmp) + 1);
	result[2] = NULL;
	return (result);
}

void	split_space(char *str, t_commands *commands)
{
	char	**result;
	int		i;
	int		j;

	i = -1;
	j = 0;
	result = ft_split_f(str, ' ', inside_quote);
	while (result[j])
		j++;
	commands->arg = malloc(sizeof(char*) * j + 1);
	j = -1;
	while (result[++i])
	{
		if (ft_strnstr("><>>", result[i], 4))
			commands->redirections = ft_strdup(result[i]);
		else if (i > 0 && ft_strnstr("><>>", result[i - 1], 4))
			commands->filename = ft_strdup(result[i]);
		else if (ft_strncmp("<<", result[i], 2) == 0)
			commands->redirections = ft_strdup(result[i]);
		else if (i > 0 && ft_strncmp("<<", result[i - 1], 2) == 0)
			commands->delimiter = ft_strdup(result[i]);
		else if (commands->com == NULL)
			commands->com = ft_strdup(result[i]);
		else
			commands->arg[++j] = ft_strdup(result[i]);
	}
	commands->arg[++j] = NULL;
	ft_free(result, 0, true);
}

t_commands	*split_pipe(char *str)
{
	char		**tmp;
	int			com_count;
	int			i;
	t_commands	*commands;

	i = -1;
	com_count = 0;
	tmp = ft_split_f(str, '|', inside_quote);
	while (tmp[com_count])
		com_count++;
	commands = malloc(sizeof(t_commands) * com_count);
	while (++i < com_count)
	{
		split_space(tmp[i], &commands[i]);
		commands[i].index = i;
		commands[i].total_index = com_count;
	}
	return (commands);
}