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

	char str[10];
	int command_num = 0;
	arr_num = malloc(num + 1);
	for (int i = 0; i < num; i++)
	{
		arr_num[i] = '0' + i + 1;
	}
	arr_num[num] = 0;
	create_list(stack_a, arr_num);
	while (1)
	{
		t_node *node_a = stack_a->top;
		t_node *node_b = stack_b->top;
		int i = -1;
		printf("%-9s", "top = ");
		if (stack_a->num)
			printf("%-5d", stack_a->top->value);
		printf("%-9s", "top = ");
		if (stack_b->num)
			printf("%-5d", stack_b->top->value);
		printf("\n");
		printf("%-9s", "bottom = ");
		if (stack_a->num)
			printf("%-5d", stack_a->bottom->value);
		printf("%-9s", "bottom = ");
		if (stack_b->num)
			printf("%-5d", stack_b->bottom->value);
		printf("\n");
		printf("%-10s%-10s\n", "stack_a", "stack_b");
		while(++i < stack_a->num || ++i < stack_b->num)
		{
			if (i < stack_a->num)
				printf("  %-10d", node_a->value);
			if (i < stack_b->num)
				printf("  %-10d", node_b->value);
			if (stack_a->num > 1)
				node_a = node_a->next;
			if (stack_b->num > 1)
				node_b = node_b->next;
			printf("\n");
		}
		scanf("%s", str);
		printf("\n\n");
		if (!ft_strncmp(str, "ra", 3))
		{
			ra_b(stack_a);
			command_num++;
		}
		else if (!ft_strncmp(str, "rb", 3))
		{
			ra_b(stack_b);
			command_num++;
		}
		else if (!ft_strncmp(str, "rr", 3))
		{
			ra_b(stack_a);
			ra_b(stack_b);
			command_num++;
		}
		else if (!ft_strncmp(str, "sa", 3))
		{
			sa_b(stack_a);
			command_num++;
		}
		else if (!ft_strncmp(str, "sb", 3))
		{
			sa_b(stack_b);
			command_num++;
		}
		else if (!ft_strncmp(str, "ss", 3))
		{
			sa_b(stack_a);
			sa_b(stack_b);
			command_num++;
		}
		else if (!ft_strncmp(str, "pa", 3))
		{
			pa_b(stack_b, stack_a);
			command_num++;
		}
		else if (!ft_strncmp(str, "pb", 3))
		{
			pa_b(stack_a, stack_b);
			command_num++;
		}
		else if (!ft_strncmp(str, "rra", 4))
		{
			rra_b(stack_a);
			command_num++;
		}
		else if (!ft_strncmp(str, "rrb", 4))
		{
			rra_b(stack_b);
			command_num++;
		}
		else if (!ft_strncmp(str, "rrr", 4))
		{
			rra_b(stack_a);
			rra_b(stack_b);
			command_num++;
		}
		else if (!ft_strncmp(str, "exit", 5))
		{
			printf("com = %d\n", command_num);
			exit(0);
		}
	}
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
