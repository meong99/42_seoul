#include "push_swap.h"

int	sa_b(t_stack *stack)
{
	int temp;

	if (stack->num > 1)
	{
		temp = stack->top->value;
		stack->top->value = stack->top->next->value;
		stack->top->next->value = temp;
		// temp_print(aa, bb);
		if (stack->stack_type == STACK_A)
			printf("sa\n");
		else
			printf("sb\n");
	}
	return (1);
}

int	pa_b(t_stack *send_stack, t_stack *receive_stack)
{
	t_node *send_top;

	send_top = send_stack->top->next;
	if (send_stack->num >= 1)
	{
		if (receive_stack->num == 0)
		{
			send_stack->top->next = send_stack->top;
			receive_stack->top = send_stack->top;
			receive_stack->bottom = send_stack->top;
		}
		else
		{
			send_stack->top->next = receive_stack->top;
			receive_stack->top = send_stack->top;
			receive_stack->bottom->next = send_stack->top;
		}
		if (send_stack->num > 1)
		{
			send_stack->top = send_top;
			send_stack->bottom->next = send_top;
		}
		send_stack->num--;
		receive_stack->num++;
		// temp_print(aa, bb);
		if (receive_stack->stack_type == STACK_A)
			printf("pa\n");
		else
			printf("pb\n");
	}
	return (1);
}
