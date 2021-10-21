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

static char	*mapping_env(char *start, char *end)
{
	char	*key;
	char	*value;
	int		i;

	i = 0;
	while (start + i <= end)
		i++;
	key = malloc(i + 1);
	i = -1;
	while (start + ++i <= end)
		key[i] = start[i];
	key[i] = 0;
	value = ret_env_value(key);
	free(key);
	return (value);
}

char	*mapping_dollar(char *str)
{
	char	*start;
	char	*end;
	char	*value;
	char	*result;
	char	*tmp;

	result = ft_strdup(str);
	while (1)
	{
		tmp = result;
		start = ft_strchr_f(tmp, '$', SING_QUOTE, check_quote);
		if (start == NULL)
			break ;
		end = ft_strchr_f(start + 1, '$', SING_QUOTE, check_quote);
		if (end == NULL)
			end = start + ft_strlen(start);
		end--;
		while (end > start + 1 && ft_isdigit(*end))
			end--;
		value = mapping_env(start + 1, end);
		result = ft_submap(tmp, start, end, value);
		free(value);
		free(tmp);
	}
	return (result);
}
