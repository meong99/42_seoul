/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_export_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:46:03 by mchae             #+#    #+#             */
/*   Updated: 2021/11/24 18:11:51 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*deep_copy(t_env *env)
{
	t_env	*temp;
	t_env	*head;

	head = new_env_node(env->key, env->value, NULL);
	temp = head;
	env = env->next;
	while (env)
	{
		temp->next = new_env_node(env->key, env->value, NULL);
		temp = temp->next;
		env = env->next;
	}
	return (head);
}

void	print_export_env(t_env *env)
{
	t_env	*node;
	t_env	*temp;

	node = deep_copy(env);
	sorting_export(node, node->next, &node);
	temp = node;
	while (temp)
	{
		printf("declare -x %s", temp->key);
		if (temp->value)
			printf("=\"%s\"", temp->value);
		printf("\n");
		temp = temp->next;
	}
	while (node)
	{
		temp = node->next;
		free(node->key);
		free(node->value);
		free(node);
		node = temp;
	}
}
