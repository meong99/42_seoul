#include "push_swap.h"

int	f_s_swap(t_node *first, t_node *second, t_stack *stack)
{
	t_node *temp;

	temp = first;
	first->next = second->next;
	first->previous = second;
	second->next = first;
	second->previous = temp->previous;
	first->next->previous = first;
	second->previous->next = second;
	stack->top = second;
	return (1);
}

int	push_stack(t_stack *stack_send, t_stack *stack_receive)
{
	t_node *temp_receive;
	t_node *temp_send;

	temp_receive = stack_receive->top;
	temp_send = stack_send->top->next;
	stack_receive->top = stack_send->top;
	stack_receive->top->next = temp_receive;
	stack_receive->top->previous = stack_receive->bottom;
	stack_receive->bottom->next = stack_receive->top;
	temp_receive->previous = stack_receive->top;
	stack_send->top = temp_send;
	temp_send->previous = stack_send->bottom;
	stack_send->bottom->next = temp_send;
	return (1);
}

int	rotate_stack(t_stack *stack)
{
	t_node *temp;

	temp = stack->top;
	stack->top = stack->top->next;
	stack->bottom = temp;

	return (1);
}

int	reverse_rotate_stack(t_stack *stack)
{
	t_node *temp;

	temp = stack->top;
	stack->top = stack->bottom;
	stack->bottom = temp;

	return (1);
}

