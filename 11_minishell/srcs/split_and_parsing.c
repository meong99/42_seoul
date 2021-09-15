#include "minishell.h"

char	**split_and_parsing(char *str, t_commands *commands)
{
	char	**result;
	int		i;

	i = -1;
	result = ft_split_f(str, ' ', inside_quote);
	while (result[++i])
	{
		if (ft_strnstr("><>>", result[i], 4))
			commands->redirections = result[i];
		else if (i > 0 && ft_strnstr("><>>", result[i - 1], 4))
			commands->filename = result[i];
		else if (ft_strncmp("<<", result[i], 2) == 0)
			commands->redirections = result[i];
		else if (i > 0 && ft_strncmp("<<", result[i - 1], 2) == 0)
			commands->delimiter = result[i];
		else if (commands->com == NULL)
			commands->com = result[i];
		else
			ft_lstadd_back(&commands->arg, ft_lstnew(result[i]));
	}
	return (result);
}