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

void	parse_redir(t_commands *commands, char *str, int mark)
{

}
