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
	if (stack->stack_type == STACK_A)
		printf("sa\n");
	else
		printf("sb\n");
	temp_print(aa, bb);
	return (1);
}

int	pa_b(t_stack *send_stack, t_stack *receive_stack)
{
	t_node *top;

	if (send_stack->num >= 1)
	{
		new_node(receive_stack, send_stack->top->value);
		if (send_stack->num > 1)
		{
			top = send_stack->top;
			top->next->previous = send_stack->bottom;
			send_stack->bottom->next = top->next;
			send_stack->top = top->next;
			free(top);
		}
		else
		{
			free(send_stack->top);
			send_stack->top = 0;
			send_stack->bottom = 0;
		}
		send_stack->num--;
	}
	if (receive_stack->stack_type == STACK_A)
	{
		printf("pa\n");
		temp_print(send_stack, receive_stack);
	}
	else
	{
		printf("pb\n");
		temp_print(receive_stack, send_stack);
	}
	return (1);
}
