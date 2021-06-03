#include "push_swap.h"

static void	find_small_than_pivot(t_stack *stack, t_stack *other_stack, int stack_block,
	int stack_range, int pivot)
{
	int count_rotate;
	int	count_push;
	t_node *temp_node;

	count_push = 0;
	count_rotate = 0;
	temp_node = stack->top;
	while (count_push + count_rotate < stack_range)
	{
		if (temp_node->value < pivot)
		{
			pa_b(stack, other_stack);
			count_push++;
		}
		else
		{
			ra_b(stack);
			count_rotate++;
		}
	}
	if (stack_block >= 2)
	{
		while (count_rotate--)
			rra_b(stack);
	}
}

static int	*get_pivot(int stack_range, int *arr_num)
{
	int pivot;

	if (stack_range % 2 == 1)
		pivot = (stack_range + 1) / 2;
	else
		pivot = stack_range / 2 + 1;
	return (&arr_num[pivot]);
}

static int	check_sorted(t_stack *stack, int stack_type)
{
	int pre_val;
	t_node *temp_node;

	pre_val = stack->top->value;
	temp_node = stack->top->next;
	while (temp_node != stack->top)
	{
		if ((stack_type == STACK_A && pre_val > temp_node->value) ||
		(stack_type == STACK_B && pre_val < temp_node->value))
			return (0);
		temp_node = temp_node->next;
	}
	return (1);
}

static void	sorting_stack(int stack_type, int stack_range, t_stack *stack, t_stack *other_stack)
{
	int pre_val;

	if (stack_type == STACK_B)
	{
		while (stack_range--)
			pa_b(stack, other_stack);
		stack = other_stack;
	}
	pre_val = stack->top->value;
	if (stack_range >= 2 && pre_val > stack->top->next->value)
	{
		sa_b(stack);
		ra_b(stack);
	}
	ra_b(stack);
}

int	push_sort(int stack_type, int stack_range, t_stack *stack, t_stack *other_stack, int *arr_num)
{
	int *pivot;
	int i;

	i = -1;
	stack->stack_block++;
	check_sorted(stack, stack_type);
	if (stack_range > 2)
	{
		pivot = get_pivot(stack_range, arr_num);
		find_small_than_pivot(stack, other_stack, stack->stack_block, stack_range, *pivot);
		push_sort(stack_type * -1, (int)(stack_range / 2), other_stack, stack, arr_num);
		push_sort(stack_type, (int)(stack_range / 2), stack, other_stack, pivot);
		stack->stack_block--;
	}
	else
		sorting_stack(stack_type, stack_range, stack, other_stack);
	return (0);
}
