#include "minishell.h"

void	parse_space(t_commands *commands, char *str)
{
	char	**spl;
	char	*mapped;
	int		i;

	spl = ft_split_f(str, ' ', BOTH, check_quote);
	ft_protect(spl);
	i = -1;
	while (spl[++i])
	{
		spl[i] = remove_quote(spl[i]);
		mapped = mapping_dollar(spl[i]);
		if (commands->com == NULL)
			commands->com = mapped;
		else
			ft_lstadd_back(&commands->arg, ft_lstnew(mapped));
		free(spl[i]);
	}
	free(spl);
}
