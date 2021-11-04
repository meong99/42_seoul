#include "minishell.h"

static char	*ret_env_value(char *key)
{
	t_env	*index;
	char	*result;

	if (ft_strncmp(key, "?", 2) == 0)
	{
		result = ft_itoa(errno);
		ft_protect(result);
		return (result);
	}
	index = g_env;
	while (index)
	{
		if (ft_strncmp(index->key, key, ft_strlen(key)) == 0)
			return (ft_strdup(index->value));
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
	ft_protect(key);
	i = -1;
	while (start + ++i <= end)
		key[i] = start[i];
	key[i] = 0;
	value = ret_env_value(key);
	ft_protect(value);
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
			{
				end--;
				break ;
			}
			else if (!check_quote(str, start + i, BOTH))
			{
				end--;
				break ;
			}
		}
	}
	while (end > start + 1 && ft_isdigit(*end))
		end--;
	return (end);
}

static int	check_heredoc(char *start)
{
	if (start == NULL)
		return (true);
	start--;
	while (*start == ' ')
		start--;
	if (*start == '<' && *(start - 1) == '<')
		return (true);
	return (false);
}

char	*mapping_dollar(char *str)
{
	char	*start;
	char	*end;
	char	*value;
	char	*result;
	char	*tmp;

	result = ft_strdup(str);
	ft_protect(result);
	while (result)
	{
		tmp = result;
		start = ft_strchr_f(tmp, '$', SINGLE_QUOTE, check_quote);
		if (start == NULL || check_heredoc(start))
			break ;
		end = set_end(start + 1, tmp);
		value = mapping_env(start + 1, end);
		result = ft_submap(tmp, start, end, value);
		ft_protect(result);
		free(value);
		free(tmp);
	}
	if (*result == 0 && *str != 0)
	{
		free(result);
		result = NULL;
	}
	return (result);
}
