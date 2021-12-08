/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:56:21 by mchae             #+#    #+#             */
/*   Updated: 2021/06/17 19:33:09 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			sa_b(t_stack *stack)
{
	int temp;

	if (stack->num > 1)
	{
		temp = stack->top->value;
		stack->top->value = stack->top->next->value;
		stack->top->next->value = temp;
	temp_print(aa, bb);
		if (stack->stack_type == STACK_A)
			write(1, "sa\n", 3);
		else
			write(1, "sb\n", 3);
	}
	return (1);
}

static void	link_stack(t_stack *send_stack, t_stack *receive_stack)
{
	t_node *send_top;

	send_top = send_stack->top->next;
	if (receive_stack->num == 0)
	{
		send_stack->top->next = send_stack->top;
		receive_stack->top = send_stack->top;
		receive_stack->bottom = send_stack->top;
	}
	else
	{
		send_stack->top->next = receive_stack->top;
		receive_stack->top = send_stack->top;
		receive_stack->bottom->next = send_stack->top;
	}
	if (send_stack->num > 1)
	{
		send_stack->top = send_top;
		send_stack->bottom->next = send_top;
	}
}

int			pa_b(t_stack *send_stack, t_stack *receive_stack)
{
	if (send_stack->num >= 1)
	{
		link_stack(send_stack, receive_stack);
		send_stack->num--;
		receive_stack->num++;
	temp_print(aa, bb);
		if (receive_stack->stack_type == STACK_A)
			write(1, "pa\n", 3);
		else
			write(1, "pb\n", 3);
	}
	return (1);
}
