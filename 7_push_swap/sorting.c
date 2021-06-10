/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:00:34 by mchae             #+#    #+#             */
/*   Updated: 2021/06/10 20:56:01 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_aligned(t_stack *stack)
{
	int		most;
	t_node	*node;

	most = stack->top->value;
	node = stack->top->next;
	while (node != stack->top)
	{
		if (stack->stack_type == STACK_A)
		{
			if (most > node->value)
				return (0);
		}
		else
		{
			if (most < node->value)
				return (0);
		}
		most = node->value;
		node = node->next;
	}
	return (1);
}

static int	get_most(t_stack *stack)
{
	int ret;

	ret = stack->top->value;
	if (stack->stack_type == STACK_A)
	{
		if (ret < stack->bottom->value)
			ret = stack->bottom->value;
		if (ret < stack->top->next->value)
			ret = stack->top->next->value;
	}
	else
	{
		if (ret > stack->bottom->value)
			ret = stack->bottom->value;
		if (ret > stack->top->next->value)
			ret = stack->top->next->value;
	}
	return (ret);
}

static void	one_block(t_stack *stack, t_stack *other_stack)
{
	int most;

	most = get_most(stack);
	while (!check_aligned(stack))
	{
		if (stack->top->value == most)
			ra_b(stack);
		else if (stack->stack_type == STACK_A &&\
			stack->top->value > stack->top->next->value)
			sa_b(stack);
		else if (stack->stack_type == STACK_B &&\
			stack->top->value < stack->top->next->value)
			sa_b(stack);
		else
			rra_b(stack);
	}
	if (other_stack->num && other_stack->num <= 3 &&\
	!check_aligned(other_stack))
		one_block(other_stack, stack);
}

void		sort_by_range(t_stack *stack_a, t_stack *stack_b, int stack_range)
{
	if (*stack_a->low_num == 0)
		stack_a->stack_block++;
	if (stack_range == 1)
	{
		ra_b(stack_a);
		(*stack_a->low_num)++;
	}
	else if (stack_range == 2)
		range_2(stack_a);
	else
		range_3(stack_a, stack_b, stack_range);
}

void		sorting(t_stack *stack, t_stack *other_stack, int stack_range)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = stack;
	stack_b = other_stack;
	if (stack->stack_block == 1 && stack->num > 0)
		one_block(stack, other_stack);
	if (stack->stack_type == STACK_B)
	{
		stack_a = other_stack;
		stack_b = stack;
		push_stack_a(stack, other_stack, stack_range);
	}
	if (!check_aligned(stack_a))
		sort_by_range(stack_a, stack_b, stack_range);
	stack->stack_block--;
}
