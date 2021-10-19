#include "minishell.h"

int	check_redir(char *str)
{
	char	*tmp;

	tmp = ft_strchr_f(str, '<', check_quote);
	if (tmp)
	{
		if (*tmp == '<' && *(tmp + 1) == '<')
			return (HEREDOC);
		if (*tmp == '<')
			return (LESS);
	}
	tmp = ft_strchr_f(str, '>', check_quote);
	if (tmp)
	{
		if (*tmp == '>' && *(tmp + 1) == '>')
			return (APPEND);
		if (*tmp == '>')
			return (GREATER);
	}
	return (NO_REDIR);
}

char	*parse_redir(t_commands *commands, char *str, int mark)
{
	char	*start;
	char	end;

	if (mark == NO_REDIR)
		return (ft_strdup(str));
	if (mark == LESS || )
}
