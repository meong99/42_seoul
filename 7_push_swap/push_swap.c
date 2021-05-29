#include "push_swap.h"
#include <stdio.h>

int	new_node(t_stack *stack, int num)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	node->value = num;
	node->next = node;
	node->previous = node;
	stack->num++;
	if (stack->top == NULL)
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		t_node *temp;

		temp = stack->top;
		stack->top = node;
		node->next = temp;
		node->previous = stack->bottom;
		temp->previous = node;
		stack->bottom->next = node;
	}
	return (0);
}

static int	create_list(t_stack *stack, char *arr_num)
{
	int i = -1;
	while (arr_num[++i])
		new_node(stack, arr_num[i] - '0');
	return (0);
}

static int	use_commands(t_stack *stack_a, t_stack *stack_b)
{
	char *arr_num;
	int num = 10;
	arr_num = malloc(num + 1);

	for (int i = 0; i < num; i++)
	{
		arr_num[i] = '0' + i + 1;
	}
	arr_num[num] = 0;
	create_list(stack_a, arr_num);
	stack_b = 0;

	return (0);
}

int	main(void)
{
	t_stack stack_a;
	t_stack stack_b;

	stack_a.top = NULL;
	stack_a.bottom = NULL;
	stack_b.top = NULL;
	stack_b.bottom = NULL;
	stack_a.num = 0;
	stack_b.num = 0;
	use_commands(&stack_a, &stack_b);
	return (0);
}
