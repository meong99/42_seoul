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
		temp_node = temp_node->next;
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

	pivot = stack_range / 2 + 1;
	return (&arr_num[pivot - 1]);
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
static int get_stack_range(int stack_range)
{
	return (stack_range % 2 == 1) ? (stack_range / 2 + 1) : (stack_range / 2);
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
		t_stack *stack_a = stack;
		t_stack *stack_b = other_stack;
		if (stack_type == STACK_B)
		{
			stack_a = other_stack;
			stack_b = stack;
		}
		t_node *node_a = stack_a->top;
		t_node *node_b = stack_b->top;
		printf("%-10s%-10s\n", "stack_a", "stack_b");
		while(++i < stack_a->num || i < stack_b->num)
		{
			if (i < stack_a->num)
				printf("  %-10d", node_a->value);
			else if (i >= stack_a->num)
				printf("  %-10c", ' ');
			if (i < stack_b->num)
				printf("  %-10d", node_b->value);
			else if (i >= stack_b->num)
				printf("  %-10c", ' ');
			if (stack_a->num > 1)
				node_a = node_a->next;
			if (stack_b->num > 1)
				node_b = node_b->next;
			printf("\n");
		}
		push_sort(stack_type * -1, stack_range / 2, other_stack, stack, arr_num);
		push_sort(stack_type, get_stack_range(stack_range), stack, other_stack, pivot);
		stack->stack_block--;
	}
	else
	{
		sorting_stack(stack_type, stack_range, stack, other_stack);
		t_stack *stack_a = stack;
		t_stack *stack_b = other_stack;
		if (stack_type == STACK_B)
		{
			stack_a = other_stack;
			stack_b = stack;
		}
		t_node *node_a = stack_a->top;
		t_node *node_b = stack_b->top;
		printf("%-10s%-10s\n", "stack_a", "stack_b");
		while(++i < stack_a->num || i < stack_b->num)
		{
			if (i < stack_a->num)
				printf("  %-10d", node_a->value);
			else if (i >= stack_a->num)
				printf("  %-10c", ' ');
			if (i < stack_b->num)
				printf("  %-10d", node_b->value);
			else if (i >= stack_b->num)
				printf("  %-10c", ' ');
			if (stack_a->num > 1)
				node_a = node_a->next;
			if (stack_b->num > 1)
				node_b = node_b->next;
			printf("\n");
		}
	}
	return (0);
}
