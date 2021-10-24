#include "minishell.h"

char	*parse_redir(t_commands *commands, char *str)
{
	char	*new_str;
	char	*tmp;

	new_str = ft_strdup(str);
	while (true)
	{
		tmp = new_str;
		if (ft_strnstr_f(new_str, "<<", ft_strlen(new_str), check_quote))
			new_str = parse_heredoc(commands, new_str);
		else if (ft_strnstr_f(new_str, "<", ft_strlen(new_str), check_quote))
			new_str = parse_less(commands, new_str);
		else if (ft_strnstr_f(new_str, ">>", ft_strlen(new_str), check_quote))
			new_str = parse_append(commands, new_str);
		else if (ft_strnstr_f(new_str, ">", ft_strlen(new_str), check_quote))
			new_str = parse_greater(commands, new_str);
		else
			break ;
		free(tmp);
		if (errno)
			return (NULL);
	}
	return (new_str);
}
