#include "push_swap.h"

int check_low_val(t_stack *stack, t_stack *other_stack)
{
	if (stack->top->value == stack->arr_num[*stack->low_num])
	{
		pa_b(stack, other_stack);
		ra_b(other_stack);
		if ((*stack->low_num)++ == 0)
			other_stack->stack_block++;
		return (1);
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

int	quick_sort(int stack_range, t_stack *stack, t_stack *other_stack)
{
	int pivot;
	int *count;

	if (stack_range > 3)
	{
		pivot = get_pivot(stack_range, stack->arr_num, *stack->low_num);
		count = smaller_than_pivot(stack, other_stack, stack_range, pivot);
		quick_sort(count[NEXT_RANGE], other_stack, stack);
		quick_sort(stack_range - (count[CHECK_LOW] + count[NEXT_RANGE]), stack, other_stack);
	}
	else if (stack_range)
		sorting(stack, other_stack, stack_range);
	return (0);
}
