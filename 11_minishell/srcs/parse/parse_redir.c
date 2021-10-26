#include "minishell.h"

static char	*parse_redir(t_commands *commands, char *str)
{
	if (ft_strnstr_f(str, "<<", ft_strlen(str), check_quote))
		return (parse_heredoc(commands, str));
	else if (ft_strnstr_f(str, "<", ft_strlen(str), check_quote))
		return (parse_less(commands, str));
	else if (ft_strnstr_f(str, ">>", ft_strlen(str), check_quote))
		return (parse_append(commands, str));
	else if (ft_strnstr_f(str, ">", ft_strlen(str), check_quote))
		return (parse_greater(commands, str));
	else
		return (str);
}

char	*redir_handler(t_commands *commands, char *str)
{
	char	*new_str;
	char	*tmp;

	new_str = ft_strdup(str);
	ft_protect(new_str);
	while (true)
	{
		tmp = new_str;
		new_str = parse_redir(commands, new_str);
		if (ft_strncmp(tmp, new_str, ft_strlen(tmp)) == 0)
			break ;
		free(tmp);
		if (errno)
			return (new_str);
	}
	return (new_str);
}
