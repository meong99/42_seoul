#include "minishell.h"

static char	*ret_env_value(char *key)
{
	t_env	*index;

	if (ft_strncmp(key, "?", 2) == 0)
		return (ft_itoa(errno));
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
	if (start > end || !start || !end)
		return (NULL);
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

static char	*set_end(char *start, char *str)
{
	char	*end;
	int		i;

	i = -1;
	while (start[++i])
	{
		end = start + i;
		if (ft_strchr("$<>", start[i]))
		{
			if (start[i] == '$' && \
				!check_quote(str, start + i, SINGLE_QUOTE))
				break ;
			else if (!check_quote(str, start + i, BOTH))
				break ;
		}
	}
	while (end > start + 1 && ft_isdigit(*end))
		end--;
	return (end);
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
		start = ft_strchr_f(tmp, '$', SINGLE_QUOTE, check_quote);
		if (start == NULL)
			break ;
		end = set_end(start + 1, tmp);
		value = mapping_env(start + 1, end);
		result = ft_submap(tmp, start, end, value);
		free(value);
		free(tmp);
	}
	return (result);
}
