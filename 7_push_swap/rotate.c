#include "push_swap.h"

void	ra_b(t_stack *stack)
{
	t_node *temp;

	temp = stack->top;
	if (stack->num > 1)
	{
		stack->top = stack->top->next;
		stack->bottom = temp;
	}
}

int	rotate_command(t_stack *stack, t_stack *other_stack)
{
	ra_b(stack);
	if (stack->stack_type == STACK_A)
	{
		write(1, "ra\n", 3);
		temp_print(stack, other_stack);
		return (1);
	}
	else
	{
		write(1, "rb\n", 3);
		temp_print(other_stack, stack);
		return (1);
	}
	return (0);
}

void	rra_b(t_stack *stack)
{
	t_node *temp;

	temp = stack->bottom;
	if (stack->num > 1)
	{
		stack->bottom = stack->bottom->previous;
		stack->top = temp;
	}
	if (stack->stack_type == STACK_A)
		printf("rra\n");
	else
		printf("rrb\n");
	// getchar();
}

