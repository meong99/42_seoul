/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:46:10 by mchae             #+#    #+#             */
/*   Updated: 2021/11/16 18:41:00 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*find_key(char *key)
{
	t_env	*index;

	index = g_commands->env;
	while (index)
	{
		if (ft_strncmp(index->key, key, ft_strlen(key)) == 0)
			return (index);
		index = index->next;
	}
	return (NULL);
}

static void	mapping_value(char *key, char *value, char *str)
{
	t_env	*mapping;

	mapping = find_key(key);
	if (value && !mapping->value)
	{
		free(mapping->value);
		mapping->value = ft_strdup(value);
		ft_protect(mapping->value);
	}
	else if (ft_strchr(str, '='))
	{
		free(mapping->value);
		mapping->value = ft_strdup("");
		ft_protect(mapping->value);
	}
}

static void	ft_putenv(char *key, char *value, char *str)
{
	t_env	*index;

	index = g_commands->env;
	while (index->next)
		index = index->next;
	if (value == NULL && ft_strchr(str, '='))
		value = "";
	index->next = new_env_node(key, value, index->env_num);
	(*index->env_num)++;
}

static void	export_internal(t_list *arg)
{
	char	**split_var;
	t_env	*check_key;

	while (arg)
	{
		if (check_first_char((char *)arg->content) != RET_ERR_INT)
		{
			split_var = ft_split((char *)arg->content, '=');
			ft_protect(split_var);
			check_key = find_key(split_var[0]);
			if (check_key == NOT_FOUND && !check_export_error(split_var[0], \
				(char *)arg->content))
				ft_putenv(split_var[0], split_var[1], (char *)arg->content);
			else if (check_key)
				mapping_value(split_var[0], split_var[1], (char *)arg->content);
			ft_free(split_var, 0, true);
		}
		arg = arg->next;
	}
}

int	exe_export(t_commands *commands)
{
	t_list	*arg;

	arg = commands->arg;
	if (arg == NULL)
		print_export_env();
	else
		export_internal(arg);
	return (0);
}
