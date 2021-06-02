#include "push_swap.h"

void	find_small_than_pivot(t_sort_mem sort_mem)
{
	int count_rotate;
	int i;
	t_node *temp_node;

	i = -1;
	count_rotate = 0;
	temp_node = sort_mem.stack->top;
	while (++i < sort_mem.stack_range)
	{
		if ((sort_mem.stack_type == STACK_A && temp_node->value < sort_mem.pivot) ||
		(sort_mem.stack_type == STACK_B && temp_node->value >= sort_mem.pivot))
			pa_b(sort_mem.stack, sort_mem.other_stack);
		else
		{
			ra_b(sort_mem.stack);
			count_rotate++;
		}
	}
}

int	get_pivot(int stack_range, int *arr_num)
{
	int pivot;

	if (stack_range % 2 == 1)
		pivot = (stack_range + 1) / 2;
	else
		pivot = stack_range / 2 + 1;
	return (arr_num[pivot]);
}

int check_sorted(t_stack *stack, int stack_type)
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

int	push_sort(t_sort_mem sort_mem)
{
	check_sorted(sort_mem.stack, sort_mem.stack_type);
	if (sort_mem.stack_range > 2)
	{
		sort_mem.pivot = get_pivot(sort_mem.stack_range, sort_mem.arr_num);
	}
}
