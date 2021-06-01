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
		else if (!ft_strncmp(str, "p", 2))
		{
			t_node *node = stack_a->top;
			int i = -1;
			while(++i < stack_a->num)
			{
				printf("%d\n", node->value);
				node = node->next;
			}
			printf("\n\n");
		}
		else if (!ft_strncmp(str, "pp", 2))
		{
			t_node *node = stack_b->top;
			int i = -1;
			while(++i < stack_b->num)
			{
				printf("%d\n", node->value);
				node = node->next;
			}
			printf("\n\n");
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
