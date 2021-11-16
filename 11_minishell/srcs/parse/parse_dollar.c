/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:38:14 by mchae             #+#    #+#             */
/*   Updated: 2021/11/16 20:26:38 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ret_env_value(char *key, int old_errno)
{
	t_env	*index;
	char	*result;

	if (ft_strncmp(key, "?", 2) == 0)
	{
		result = ft_itoa(old_errno);
		ft_protect(result);
		return (result);
	}
	index = g_commands->env;
	while (index)
	{
		if (ft_strncmp(index->key, key, ft_strlen(key) + 1) == 0)
			return (ft_strdup(index->value));
		index = index->next;
	}
	return (NULL);
}

static char	*mapping_env(char *start, char *end, int old_errno)
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
	value = ret_env_value(key, old_errno);
	ft_protect(value);
	free(key);
	return (value);
}

static char	*set_end(char *start)
{
	char	*end;
	int		i;

	i = -1;
	while (start[++i])
	{
		end = start + i;
		if (ft_strchr("$\'\"", start[i]))
		{
			end--;
			break ;
		}
	}
	return (end);
}

static char	*check_ambiguous(char *result, char *str)
{
	if (*result == 0 && *str != 0)
	{
		free(result);
		result = NULL;
	}
	else
		result = remove_quote(result);
	return (result);
}

char	*mapping_dollar(char *str, int old_errno)
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
		while (start && (start[1] == '\"' || start[1] == '\'') && \
			check_quote(tmp, start, DOUBLE_QUOTE))
			start = ft_strchr_f(start + 1, '$', SINGLE_QUOTE, check_quote);
		if (start == NULL)
			break ;
		end = set_end(start + 1);
		value = mapping_env(start + 1, end, old_errno);
		result = ft_submap(tmp, start, end, value);
		ft_protect(result);
		free(value);
		free(tmp);
	}
	return (check_ambiguous(result, str));
}
