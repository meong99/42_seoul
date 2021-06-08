/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 21:26:04 by mchae             #+#    #+#             */
/*   Updated: 2021/06/08 23:04:37 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	range_3(t_stack *stack, t_stack *other_stack, int stack_range)
{
	int push;
	int swap;

	push = 0;
	swap = 0;
	while (stack_range)
	{
		if (stack->top->value == stack->arr_num[*stack->low_num])
		{
			ra_b(stack);
			stack_range--;
			(*stack->low_num)++;
			swap = 0;
		}
		else if (!swap && stack->top->value > stack->top->next->value)
			swap += sa_b(stack);
		else if (push < 2)
			push += pa_b(stack, other_stack);
		else
			while (push)
				push -= pa_b(other_stack, stack);
	}
}

void	range_2(t_stack *stack)
{
	if (stack->top->value > stack->top->next->value)
		sa_b(stack);
	ra_b(stack);
	ra_b(stack);
	(*stack->low_num) = (*stack->low_num) + 2;
}

void	push_stack_a(t_stack *stack, t_stack *other_stack, int stack_range)
{
	int i;

	i = -1;
	while (++i < stack_range)
		pa_b(stack, other_stack);
}
