/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_ctrl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:06:47 by mchae             #+#    #+#             */
/*   Updated: 2020/11/13 20:54:15 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_info	*new_list(void)
{
	t_info *node;

	node = (t_info*)malloc(sizeof(t_info));
	node->flags = -1;
	node->format = -1;
	node->next = NULL;
	node->precision = 0;
	node->sign = -1;
	node->width = 0;
	node->variable = 0;
	return (node);
}

t_info	*find_end_list(t_info **head)
{
	t_info	*node;

	node = *head;
	if (!*head)
	{
		*head = new_list();
		return (*head);
	}
	else
	{
		while (node->next != 0)
		{
			node = node->next;
		}
	}
	node->next = new_list();
	return (node->next);
}

void	free_node(t_info **node)
{
	t_info *temp;

	temp = *node;
	free(temp->variable);
	*node = temp->next;
	free(temp);
}
