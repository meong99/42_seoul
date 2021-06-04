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
	getchar();
}

int	rotate_command(t_stack *stack, t_stack *other_stack)
{
	if (stack->command == other_stack->command)
	{
		ra_b(stack);
		ra_b(other_stack);
		write(1, "rr\n", 3);
		stack->command = 0;
		other_stack->command = 0;
		temp_print(stack, other_stack);
		return (1);
	}
	else if (stack->command)
	{
		ra_b(stack);
		write(1, "ra\n", 3);
		stack->command = 0;
		temp_print(stack, other_stack);
		return (1);
	}
	return (0);
}

void	rra_b(t_stack *stack)
{
	t_node *temp;

	getchar();
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
}

