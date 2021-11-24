/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:46:10 by mchae             #+#    #+#             */
/*   Updated: 2021/11/24 18:44:42 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*find_key(t_env *head, char *key)
{
	while (head)
	{
		if (ft_strncmp(head->key, key, ft_strlen(key)) == 0)
			return (head);
		head = head->next;
	}
	return (NULL);
}

static void	mapping_value(t_env *head, char *key, char *value, char *str)
{
	t_env	*mapping;

	mapping = find_key(head, key);
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

static void	ft_putenv(t_env *head, char *key, char *value, char *str)
{
	while (head->next)
		head = head->next;
	if (value == NULL && ft_strchr(str, '='))
		value = "";
	head->next = new_env_node(key, value, head->env_num);
	(*head->env_num)++;
}

static void	export_internal(t_list *arg, t_env *head)
{
	char	**split_var;
	t_env	*check_key;

	while (arg)
	{
		if (check_first_char((char *)arg->content) != RET_ERR_INT)
		{
			split_var = ft_split((char *)arg->content, '=');
			ft_protect(split_var);
			check_key = find_key(head, split_var[0]);
			if (check_key == NOT_FOUND && !check_export_error(split_var[0], \
				(char *)arg->content))
				ft_putenv(head, split_var[0], \
				split_var[1], (char *)arg->content);
			else if (check_key)
				mapping_value(head, split_var[0], \
				split_var[1], (char *)arg->content);
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
		print_export_env(commands->env);
	else
		export_internal(arg, commands->env);
	return (0);
}
