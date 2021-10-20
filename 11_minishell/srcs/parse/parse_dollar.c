#include "minishell.h"

static char	*ret_env_value(char *key)
{
	t_env	*index;

	index = g_env;
	while (index)
	{
		if (ft_strncmp(index->key, key, ft_strlen(key)) == 0)
			return (index->value);
		index = index->next;
	}
	return (NULL);
}

static char	*ret_mapped_var(char *target)
{
	char	*value;

	value = ret_env_value(target);
	return (ft_strdup(value));
}

static void	mapping_var(char **target)
{
	char	**spl;
	char	*result;
	char	*value;
	char	*tmp;
	int		i;

	spl = ft_split_f(*target, '$', SING_QUOTE, check_quote);
	i = -1;
	tmp = *target;
	result = ft_strdup("");
	while (spl[++i])
	{
		tmp = ft_strnstr(tmp, spl[i], ft_strlen(*target)) - 1;
		if (*tmp == '$')
			value = ret_mapped_var(spl[i]);
		else
			value = ft_strdup(spl[i]);
		result = ft_strjoin_free(result, value);
		free(value);
		value = 0;
	}
	free(*target);
	*target = result;
}

void	mapping_dollar(t_commands *commands)
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
		if (ft_strchr_f(arg, '$', SING_QUOTE, check_quote))
			mapping_var(&arg);
		i = i->next;
	}
}
