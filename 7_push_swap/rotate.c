/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:56:13 by mchae             #+#    #+#             */
/*   Updated: 2021/06/09 18:38:23 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra_b(t_stack *stack)
{
	t_node *temp;

	temp = stack->top;
	if (stack->num > 1)
	{
		stack->top = stack->top->next;
		stack->bottom = temp;
		if (stack->stack_type == STACK_A)
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
	}
	return (1);
}

int	rra_b(t_stack *stack)
{
	t_node *temp;
	t_node *pre_bottom;

	pre_bottom = stack->top;
	while (pre_bottom->next != stack->bottom)
		pre_bottom = pre_bottom->next;
	temp = stack->bottom;
	if (stack->num > 1)
	{
		stack->bottom = pre_bottom;
		stack->top = temp;
		if (stack->stack_type == STACK_A)
			write(1, "rra\n", 4);
		else
			write(1, "rrb\n", 4);
	}
	return (1);
}
