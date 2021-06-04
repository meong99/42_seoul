#include "push_swap.h"

int	new_node(t_stack *stack, int num)
{
	t_node *node;
	t_node *temp;

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
	int i = num;
	while (--i >= 0)
		new_node(stack, arr_num[i]);
	return (0);
}

static void	sort_arr_num(int *arr_num, int n)
{
	int	i;
	int	j;
	int	least;
	int	temp;

	i = -1;
	while (++i < n - 1)
	{
		least = i;
		j = i;
		while(++j < n)
		{
			if(arr_num[j] < arr_num[least])
				least = j;
		}
		if(i != least)
		{
			temp = arr_num[i];
			arr_num[i] = arr_num[least];
			arr_num[least] = temp;
		}
	}
}

static int	use_commands(t_stack *stack_a, t_stack *stack_b, int *arr_num, int num)
{
	create_list(stack_a, arr_num, num);
	sort_arr_num(arr_num, num);
	push_sort(STACK_A, num, stack_a, stack_b, arr_num);
	return (0);
}

void	init_stack(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->top = NULL;
	stack_a->bottom = NULL;
	stack_b->top = NULL;
	stack_b->bottom = NULL;
	stack_a->num = 0;
	stack_b->num = 0;
	stack_a->stack_type = STACK_A;
	stack_b->stack_type = STACK_B;
}

int	*av_to_arri(int *arr_len, char *arg)
{
	int i;
	char **temp;
	int *arr_num;

	i = -1;
	*arr_len = 0;
	temp = ft_split(arg, ' ');
	while (temp[*arr_len])
		(*arr_len)++;
	arr_num = malloc(sizeof(int) * (*arr_len));
	while (++i < *arr_len)
		arr_num[i] = ft_atoi(temp[i]);
	return (arr_num);
}

int	main(int ac, char **av)
{
	t_stack stack_a;
	t_stack stack_b;
	int *arr_num;
	int arr_len;

	if (ac < 2)
		exit(-1);
	arr_num = av_to_arri(&arr_len, av[1]);
	init_stack(&stack_a, &stack_b);
	use_commands(&stack_a, &stack_b, arr_num, arr_len);
	return (0);
}
