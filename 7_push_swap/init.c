/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:56:22 by mchae             #+#    #+#             */
/*   Updated: 2021/06/08 19:57:50 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	new_node(t_stack *stack, int num)
{
	t_node *node;
	t_node *temp;

	node = ft_malloc(sizeof(t_node));
	node->value = num;
	node->next = node;
	node->previous = node;
	stack->num++;
	if (stack->top == NULL)
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		temp = stack->top;
		stack->top = node;
		node->next = temp;
		node->previous = temp->previous;
		temp->previous = node;
		stack->bottom->next = node;
	}
	return (0);
}

int	create_list(t_stack *stack, int *arr_num, int num)
{
	int i = num;
	while (--i >= 0)
		new_node(stack, arr_num[i]);
	return (0);
}

void	init_stack(t_stack *stack, int *arr_num, int *low_num, int type)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->num = 0;
	stack->stack_type = type;
	stack->arr_num = arr_num;
	stack->low_num = low_num;
	stack->stack_block = 0;
	if (type == STACK_A)
	stack->stack_block = 1;
}
