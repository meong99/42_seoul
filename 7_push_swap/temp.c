#include "push_swap.h"

void temp_print(t_stack *stack, t_stack *other_stack)
{
	int i = -1;
	t_stack *stack_a = stack;
	t_stack *stack_b = other_stack;
	if (stack->stack_type == STACK_B)
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
