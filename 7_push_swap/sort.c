#include "push_swap.h"

// int	check_top(t_stack *stack_a, t_stack *stack_b)
// {
// 	//무조건 스왑 안되게 조건 걸기
// 	if (stack_a->top && stack_a->top->value > stack_a->top->next->value)
// 		stack_a->command = SWAP;
// 	else if (stack_b->top && stack_b->top->value < stack_b->top->next->value)
// 		stack_b->command = SWAP;
// 	return (swap_command(stack_a, stack_b));
// }

static int	set_command(t_stack *stack, t_stack *other_stack)
{
	int swaped;

	swaped = 0;
	// if (stack->stack_type == STACK_A)
	// 	swaped = check_top(stack, other_stack);
	// else
	// 	swaped = check_top(other_stack, stack);
	if (!swaped)
	{
		// if (other_stack->stack_block == 1)
		// 	other_stack->command = ROTATE;
		return (rotate_command(stack, other_stack));
	}
	return (0);
}

void check_low_val(t_stack *stack, t_stack *other_stack, int *stack_range)
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
			temp_print(other_stack, stack);
			if ((*stack->low_num)++ == 0)
				other_stack->stack_block++;
		}
		else
		{
			ra_b(stack);
			temp_print(stack, other_stack);
			if ((*stack->low_num)++ == 0)
				stack->stack_block++;
		}
		(*stack_range)--;
	}
}

static void	smaller_than_pivot(t_stack *stack, t_stack *other_stack,\
	int *stack_range, int pivot)
{
	int count_rotate;
	int	count_push;
	t_stack *stack_a;

	if (stack->stack_type == STACK_A)
		stack_a = stack;
	else
		stack_a = other_stack;
	count_push = 0;
	count_rotate = 0;
	while (count_push < *stack_range / 2)
	{
		if (stack_a->stack_block > 1 || stack->stack_type == STACK_B)
			check_low_val(stack, other_stack, stack_range);
		if (stack->top->value < pivot)
			count_push += pa_b(stack, other_stack);
		else
			count_rotate += set_command(stack, other_stack);
	}
	if (stack->stack_block >= 2)
	{
		while (count_rotate--)
		{
			rra_b(stack);
			temp_print(stack, other_stack);
		}
	}
}

static int	*get_pivot(int stack_range, int *arr_num)
{
	int pivot;

	pivot = stack_range / 2 + 1;
	return (&arr_num[pivot - 1]);
}

int	push_sort(int stack_range, t_stack *stack, t_stack *other_stack, int *arr_num)
{
	int *pivot;
	stack->stack_block++;
	if (stack_range > 2)
	{
		pivot = get_pivot(stack_range, arr_num);
		smaller_than_pivot(stack, other_stack, &stack_range, *pivot);
		// temp_print(stack, other_stack);
		push_sort(stack_range / 2, other_stack, stack, arr_num);
		push_sort(((stack_range % 2 == 1) ? (stack_range / 2 + 1) : (stack_range / 2)), stack, other_stack, pivot);
	}
	stack->stack_block--;
	return (0);
}
