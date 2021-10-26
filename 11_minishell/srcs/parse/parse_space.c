#include "minishell.h"

void	parse_space(t_commands *commands, char *str)
{
	char	**spl;
	int		i;

	spl = ft_split_f(str, ' ', BOTH, check_quote);
	ft_protect(spl);
	i = -1;
	while (spl[++i])
	{
		spl[i] = remove_quote(spl[i]);
		if (commands->com == NULL)
		{
			commands->com = ft_strdup(spl[i]);
			ft_protect(commands->com);
		}
		else
		{
			ft_lstadd_back(&commands->arg, ft_lstnew(ft_strdup(spl[i])));
			ft_protect(commands->arg);
		}
		free(spl[i]);
	}
	free(spl);
}
