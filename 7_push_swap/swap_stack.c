#include "push_swap.h"

int	sa_b(t_node *first, t_node *second, t_stack *stack)
{
	t_node *temp;

	temp = first;
	first->previous->next = second;
	second->next->previous = first;
	stack->top = second;
	first->next = second->next;
	first->previous = second;
	second->next = first;
	second->previous = temp->previous;
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
		send_stack->top->previous->next = temp;
		free(send_stack->top);
		send_stack->top = temp;
	}
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
	stack->bottom = temp;

	return (1);
}

