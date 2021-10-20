#include "minishell.h"

void	parse_space(t_commands *commands, char *str)
{
	char	**spl;
	int		i;

	spl = ft_split_f(str, ' ', BOTH, check_quote);
	i = -1;
	while (spl[++i])
	{
		if (commands->com == NULL)
			commands->com = ft_strdup(spl[i]);
		else
			ft_lstadd_back(&commands->arg, ft_lstnew(ft_strdup(spl[i])));
		free(spl[i]);
	}
	free(spl);
}
