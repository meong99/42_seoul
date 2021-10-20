#include "minishell.h"

static char	*ret_var_name(char *target)
{

}

static void	mapping_var(char **target)
{
	char	*tmp;

	tmp = *target;

}

static void	mapping_dollar(t_commands *commands)
{
	t_list	*i;
	char	*arg;

	i = commands->arg;
	if (ft_strchr_f(commands->com, '$', SING_QUOTE, check_quote))
		mapping_var(&commands->com);
	if (ft_strchr_f(commands->redir_input, '$', SING_QUOTE, check_quote))
		mapping_var(&commands->redir_input);
	if (ft_strchr_f(commands->redir_out_file, '$', SING_QUOTE, check_quote))
		mapping_var(&commands->redir_out_file);
	while (i)
	{
		arg = (char *)i->content;
		if (ft_strchr_f(&arg, '$', SING_QUOTE, check_quote))
			mapping_var(&arg);
		i = i->next;
	}
}

void	parse_dollar(t_commands *commands)
{
	mapping_dollar(commands);
}
