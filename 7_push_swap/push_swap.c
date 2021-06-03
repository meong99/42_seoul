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
	int arr_num[10] = {8, 10, 9, 5, 1, 3, 2, 7, 6, 4};
	// srand((unsigned int)time(NULL));
	// for (int i = 0; i < num; i++)
	// {
	// 	arr_num[i] = rand() % 10 + 1;
	// 	for (int j = 0; j < i; j++)
	// 	{
	// 		if (arr_num[j] == arr_num[i])
	// 		{
	// 			arr_num[i] = rand() % 10 + 1;
	// 			j = -1;
	// 		}
	// 	}
	// 	printf("%d ", arr_num[i]);
	// }
	// printf("\n");
	create_list(stack_a, arr_num, num);
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
	asd = 0;
	use_commands(&stack_a, &stack_b);
	printf("comm = %d\n", asd);
	return (0);
}
