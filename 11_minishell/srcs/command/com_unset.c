/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:46:23 by mchae             #+#    #+#             */
/*   Updated: 2021/11/24 18:04:54 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*ret_befor(t_env *criterion, t_env *head)
{
	while (head)
	{
		if (head->next == criterion || head == criterion)
			return (head);
		head = head->next;
	}
	return (NULL);
}

static t_env	*find_key(char *key, t_env *head)
{
	while (head)
	{
		if (ft_strncmp(head->key, key, ft_strlen(key)) == 0)
			return (head);
		head = head->next;
	}
	return (NULL);
}

static void	remove_env(t_commands *commands, char *key)
{
	t_env	*node;
	t_env	*before;

	node = find_key(key, commands->env);
	if (node == NULL)
		return ;
	before = ret_befor(node, commands->env);
	before->next = node->next;
	free(node->key);
	free(node->value);
	free(node);
	(*commands->env->env_num)--;
}

int	exe_unset(t_commands *commands)
{
	t_list	*node;

	node = commands->arg;
	while (node)
	{
		if (check_unset_error((char *)node->content) != RET_ERR_INT)
			remove_env(commands, (char *)node->content);
		node = node->next;
	}
	return (0);
}
