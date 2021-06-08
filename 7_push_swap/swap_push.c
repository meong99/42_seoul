#include "push_swap.h"

void	sa_b(t_stack *stack)
{
	int temp;

	if (stack->num > 1)
	{
		temp = stack->top->value;
		stack->top->value = stack->top->next->value;
		stack->top->next->value = temp;
	}
}

int	swap_command(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->command == SWAP && stack_b->command == SWAP)
	{
		sa_b(stack_a);
		sa_b(stack_b);
		write(1, "ss\n", 3);
		stack_a->command = 0;
		stack_b->command = 0;
		temp_print(stack_a, stack_b);
	// getchar();
		return (1);
	}
	else if (stack_a->command)
	{
		sa_b(stack_a);
		write(1, "sa\n", 3);
		stack_a->command = 0;
		temp_print(stack_a, stack_b);
	// getchar();
		return (1);
	}
	return (0);
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
		// getchar();
	return (1);
}
