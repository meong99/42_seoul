#include "push_swap.h"

int	sa_b(t_stack *stack)
{
	int temp;

	if (stack->num > 1)
	{
		temp = stack->top->value;
		stack->top->value = stack->top->next->value;
		stack->top->next->value = temp;
	}
	return (1);
}

int	pa_b(t_stack *send_stack, t_stack *receive_stack)
{
	t_node *temp;

	new_node(receive_stack, send_stack->top->value);
	if (send_stack->num > 1)
	{
		temp = send_stack->top->next;
		temp->previous = send_stack->top->previous;
		send_stack->top->previous->next = send_stack->top->next;
		free(send_stack->top);
		send_stack->top = temp;
	}
	else
		free(send_stack->top);
	send_stack->num--;
	return (1);
}

int	ra_b(t_stack *stack)
{
	t_node *temp;

	temp = stack->top;
	stack->top = stack->top->next;
	stack->bottom = temp;

	return (1);
}

int	rra_b(t_stack *stack)
{
	t_node *temp;

	temp = stack->top;
	stack->top = stack->bottom;
	stack->bottom = stack->bottom->previous;

	return (1);
}

