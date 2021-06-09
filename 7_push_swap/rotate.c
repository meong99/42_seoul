#include "push_swap.h"

int	ra_b(t_stack *stack)
{
	t_node *temp;

	temp = stack->top;
	if (stack->num > 1)
	{
		stack->top = stack->top->next;
		stack->bottom = temp;
		// temp_print(aa, bb);
		if (stack->stack_type == STACK_A)
			printf("ra\n");
		else
			printf("rb\n");
	}
	return (1);
}

int	rra_b(t_stack *stack)
{
	t_node *temp;
	t_node *pre_bottom;

	pre_bottom = stack->top;
	while (pre_bottom->next != stack->bottom)
		pre_bottom = pre_bottom->next;
	temp = stack->bottom;
	if (stack->num > 1)
	{
		stack->bottom = pre_bottom;
		stack->top = temp;
		// temp_print(aa, bb);
		if (stack->stack_type == STACK_A)
			printf("rra\n");
		else
			printf("rrb\n");
	}
	return (1);
}

