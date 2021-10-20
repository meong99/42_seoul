#include "minishell.h"

static int	check_redir(char *str)
{
	char	*tmp;

	tmp = ft_strchr_f(str, '<', BOTH, check_quote);
	if (tmp)
	{
		if (*tmp == '<' && *(tmp + 1) == '<')
			return (HEREDOC);
		if (*tmp == '<')
			return (LESS);
	}
	tmp = ft_strchr_f(str, '>', BOTH, check_quote);
	if (tmp)
	{
		if (*tmp == '>' && *(tmp + 1) == '>')
			return (APPEND);
		if (*tmp == '>')
			return (GREATER);
	}
	return (NO_REDIR);
}

char	*parse_redir(t_commands *commands, char *str)
{
	char	*new_str;
	char	*tmp;
	int		mark;

	tmp = NULL;
	new_str = ft_strdup(str);
	while (true)
	{
		mark = check_redir(new_str);
		tmp = new_str;
		if (mark == LESS)
			new_str = parse_less(commands, new_str);
		else if (mark == HEREDOC)
			new_str = parse_heredoc(commands, new_str);
		else if (mark == GREATER)
			new_str = parse_greater(commands, new_str);
		else if (mark == APPEND)
			new_str = parse_append(commands, new_str);
		else
			break ;
		free(tmp);
	}
	return (new_str);
}
