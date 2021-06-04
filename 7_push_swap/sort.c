#include "push_swap.h"

static void	find_small_than_pivot(t_stack *stack, t_stack *other_stack,
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
			temp_node = temp_node->next;
			pa_b(stack, other_stack);
			count_push++;
		}
		else
		{
			temp_node = temp_node->next;
			ra_b(stack);
			count_rotate++;
		}
	}
	if (stack->stack_block >= 2)
	{
		while (count_rotate--)
			rra_b(stack);
	}
}

static int	*get_pivot(int stack_range, int *arr_num)
{
	int pivot;

	pivot = stack_range / 2 + 1;
	return (&arr_num[pivot - 1]);
}

static void	sorting_stack(int stack_type, int stack_range, t_stack *stack, t_stack *other_stack)
{
	int pre_val;
	int i;

	i = -1;
	if (stack_type == STACK_B)
	{
		while (++i < stack_range)
			pa_b(stack, other_stack);
		stack = other_stack;
	}
	pre_val = stack->top->value;
	if (stack_range >= 2)
	{
		if (pre_val > stack->top->next->value)
			sa_b(stack);
		ra_b(stack);
	}
	ra_b(stack);
}

int	push_sort(int stack_range, t_stack *stack, t_stack *other_stack, int *arr_num)
{
	int *pivot;
	stack->stack_block++;
	if (stack_range > 2)
	{
		pivot = get_pivot(stack_range, arr_num);
		find_small_than_pivot(stack, other_stack, stack_range, *pivot);
		// temp_print(stack, other_stack);
		push_sort(stack_range / 2, other_stack, stack, arr_num);
		push_sort(((stack_range % 2 == 1) ? (stack_range / 2 + 1) : (stack_range / 2)), stack, other_stack, pivot);
	}
	else
	{
		sorting_stack(stack->stack_type, stack_range, stack, other_stack);
		// temp_print(stack, other_stack);
	}
	stack->stack_block--;
	return (0);
}
