#include "push_swap.h"

int check_low_val(t_stack *stack, t_stack *other_stack)
{
	int type_b;

	type_b = 0;
	if (stack->stack_type == STACK_B)
		type_b = 1;
	if (stack->top->value == stack->arr_num[*stack->low_num])
	{
		if (type_b)
		{
			pa_b(stack, other_stack);
			ra_b(other_stack);
			if ((*stack->low_num)++ == 0)
				other_stack->stack_block++;
			return (1);
		}
		else
		{
			ra_b(stack);
			if ((*stack->low_num)++ == 0)
				stack->stack_block++;
			return (1);
		}
	}
	return (0);
}

static int	*smaller_than_pivot(t_stack *stack, t_stack *other_stack,\
	int stack_range, int pivot)
{
	int *count;
	int i;

	i = -1;
	count = ft_malloc(sizeof(int) * 3);
	while (++i < 3)
		count[i] = 0;
	t_stack *stack_a;

	if (stack->stack_type == STACK_A)
		stack_a = stack;
	else
		stack_a = other_stack;
	while (count[CHECK_LOW] + count[NEXT_RANGE] < stack_range / 2)
	{
		if (stack->stack_type == STACK_B &&\
		stack->top->value == stack->arr_num[*stack->low_num])
			count[CHECK_LOW] += check_low_val(stack, other_stack);
		else if (stack->top->value < pivot)
		{
			if (!count[NEXT_RANGE])
				other_stack->stack_block++;
			count[NEXT_RANGE] += pa_b(stack, other_stack);
		}
		else
			count[COUNT_ROTATE] += ra_b(stack);
	}
	if (stack->stack_block >= 2)
	{
		while (count[COUNT_ROTATE]--)
			rra_b(stack);
	}
	return (count);
}

static int	get_pivot(int stack_range, int *arr_num, int temp)
{
	int pivot;

	pivot = stack_range / 2;
	return (arr_num[pivot + temp]);
}

void	sorting(t_stack *stack, t_stack *other_stack, int stack_range)
{
	int i;
	t_stack *temp;

	i = -1;
	stack->stack_block--;
	if (stack->stack_type == STACK_B)
	{
		while (++i < stack_range)
			pa_b(stack, other_stack);
		temp = stack;
		stack = other_stack;
		other_stack = temp;
	}
	if (stack_range == 1)
	{
		ra_b(stack);
		(*stack->low_num)++;
	}
	else if (stack_range == 2)
	{
		if (stack->top->value > stack->top->next->value)
			sa_b(stack);
		ra_b(stack);
		ra_b(stack);
		(*stack->low_num) = (*stack->low_num) + 2;
	}
	else
	{
		int push = 0;
		int swap = 0;
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
}

int	push_sort(int stack_range, t_stack *stack, t_stack *other_stack)
{
	int pivot;
	int *count;

	if (stack_range > 3)
	{
		pivot = get_pivot(stack_range, stack->arr_num, *stack->low_num);
		count = smaller_than_pivot(stack, other_stack, stack_range, pivot);
		push_sort(count[NEXT_RANGE], other_stack, stack);
		push_sort(stack_range - (count[CHECK_LOW] + count[NEXT_RANGE]), stack, other_stack);
	}
	else if (stack_range)
		sorting(stack, other_stack, stack_range);
	return (0);
}
