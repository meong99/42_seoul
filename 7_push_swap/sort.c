#include "push_swap.h"

void	find_small_than_pivot(t_stack *stack, t_stack *other_stack, int stack_block,
	int stack_range, int stack_type, int pivot)
{
	int count_rotate;
	int	count_push;
	t_node *temp_node;

	count_push = 0;
	count_rotate = 0;
	temp_node = stack->top;
	while (count_push + count_rotate < stack_range)
	{
		if ((stack_type == STACK_A && temp_node->value < pivot) ||
		(stack_type == STACK_B && temp_node->value >= pivot))
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

void	sorting_stack(t_sort_mem sort_mem, int stack_range)
{

}

int	push_sort(int stack_type, int stack_range, t_stack *stack, t_stack *other_stack, int *arr_num)
{
	int return_num;
	int pivot;
	int i;

	i = -1;
	return_num = stack_range;
	stack->stack_block++;
	check_sorted(stack, stack_type);
	if (stack_range > 2)
	{
		pivot = get_pivot(stack_range, arr_num);
		find_small_than_pivot(stack, other_stack, stack->stack_block, stack_range, stack_type, pivot);
		return_num = push_sort(stack_type * -1, (int)(stack_range / 2), other_stack, stack, arr_num);
		push_sort(stack_type, );
		while (++i < return_num)
			pa_b(other_stack, stack);
		stack->stack_block--;
	}
	// else
	// 	sorting_stack();
	return (return_num);
}
