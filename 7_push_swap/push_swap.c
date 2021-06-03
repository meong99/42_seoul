#include "push_swap.h"

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
		node->previous = temp->previous;
		temp->previous = node;
		stack->bottom->next = node;
	}
	return (0);
}

static int	create_list(t_stack *stack, int *arr_num, int num)
{
	int i = -1;
	while (++i < num)
		new_node(stack, arr_num[i]);
	return (0);
}

void	sort_arr_num(int *arr_num, int n)
{
	int i, j, least, temp = 0;

  for(i=0; i<n-1; i++){
    least = i;

    // 최솟값을 탐색한다.
    for(j=i+1; j<n; j++){
      if(arr_num[j]<arr_num[least])
        least = j;
    }

    // 최솟값이 자기 자신이면 자료 이동을 하지 않는다.
    if(i != least){
        SWAP(arr_num[i], arr_num[least], temp);
    }
  }
}

static int	use_commands(t_stack *stack_a, t_stack *stack_b)
{
	int num = 10;
	int arr_num[num];
	int check[20] = {0};

	// for (int i = 0; i < num; i++)
	// {
	// 	arr_num[i] = i + 1;
	// }
	srand((unsigned int)time(NULL));
	for (int i = 0; i < num; i++)
	{
		int rand_num = (rand() % 20);
		while (check[rand_num])
			rand_num = (rand() % 20);
		arr_num[i] = rand_num + 1;
		check[rand_num] = 1;
	}
	create_list(stack_a, arr_num, num);
	// while (1)
	// {
	sort_arr_num(arr_num, num);
	push_sort(STACK_A, num, stack_a, stack_b, arr_num);
		t_node *node_a = stack_a->top;
		t_node *node_b = stack_b->top;
		printf("%-10s%-10s\n", "stack_a", "stack_b");
		int i = -1;
		while(++i < stack_a->num || i < stack_b->num)
		{
			if (i < stack_a->num)
				printf("  %-10d", node_a->value);
			else if (i >= stack_a->num)
				printf("  %-10c", ' ');
			if (i < stack_b->num)
				printf("  %-10d", node_b->value);
			else if (i >= stack_b->num)
				printf("  %-10c", ' ');
			if (stack_a->num > 1)
				node_a = node_a->next;
			if (stack_b->num > 1)
				node_b = node_b->next;
			printf("\n");
		}
		// while (++i < stack_a->num)
		// {
		// 	printf("%d\n", node_a->value);
		// 	node_a = node_a->next;
		// }
		// scanf("%s", str);
		// printf("\n\n");
		// if (!ft_strncmp(str, "ra", 3))
		// {
		// 	ra_b(stack_a);
		// 	command_num++;
		// }
		// else if (!ft_strncmp(str, "rb", 3))
		// {
		// 	ra_b(stack_b);
		// 	command_num++;
		// }
		// else if (!ft_strncmp(str, "rr", 3))
		// {
		// 	ra_b(stack_a);
		// 	ra_b(stack_b);
		// 	command_num++;
		// }
		// else if (!ft_strncmp(str, "sa", 3))
		// {
		// 	sa_b(stack_a);
		// 	command_num++;
		// }
		// else if (!ft_strncmp(str, "sb", 3))
		// {
		// 	sa_b(stack_b);
		// 	command_num++;
		// }
		// else if (!ft_strncmp(str, "ss", 3))
		// {
		// 	sa_b(stack_a);
		// 	sa_b(stack_b);
		// 	command_num++;
		// }
		// else if (!ft_strncmp(str, "pa", 3))
		// {
		// 	pa_b(stack_b, stack_a);
		// 	command_num++;
		// }
		// else if (!ft_strncmp(str, "pb", 3))
		// {
		// 	pa_b(stack_a, stack_b);
		// 	command_num++;
		// }
		// else if (!ft_strncmp(str, "rra", 4))
		// {
		// 	rra_b(stack_a);
		// 	command_num++;
		// }
		// else if (!ft_strncmp(str, "rrb", 4))
		// {
		// 	rra_b(stack_b);
		// 	command_num++;
		// }
		// else if (!ft_strncmp(str, "rrr", 4))
		// {
		// 	rra_b(stack_a);
		// 	rra_b(stack_b);
		// 	command_num++;
		// }
		// else if (!ft_strncmp(str, "exit", 5))
		// {
		// 	printf("com = %d\n", command_num);
		// 	exit(0);
		// }
		// str[0] = 0;
	// }
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
	printf("comm = %d\n", asd);
	return (0);
}
