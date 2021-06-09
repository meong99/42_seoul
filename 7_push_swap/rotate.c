#include "push_swap.h"

int	ra_b(t_stack *stack)
{
	t_node *temp;

	temp = stack->top;
	if (stack->num > 1)
	{
		stack->top = stack->top->next;
		stack->bottom = temp;
	}
	if (stack->stack_type == STACK_A)
		printf("ra\n");
	else
		printf("rb\n");
	// temp_print(aa, bb);
	return (1);
}

int	rra_b(t_stack *stack)
{
	t_node *temp;

	temp = stack->bottom;
	if (stack->num > 1)
	{
		stack->bottom = stack->bottom->previous;
		stack->top = temp;
	}
	// temp_print(aa, bb);
	if (stack->stack_type == STACK_A)
		printf("rra\n");
	else
		printf("rrb\n");
	return (1);
}

