#include "push_swap.h"

int	new_node(t_stack *stack, int num)
{
	t_node *node;
	t_node *temp;

	node = ft_malloc(sizeof(t_node));
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

static int	start_sort(t_stack *stack_a, t_stack *stack_b, int num)
{
	create_list(stack_a, stack_a->arr_num, num);
	sort_arr_num(stack_a->arr_num, num);
	temp_print(stack_a, stack_b);
	push_sort(num, stack_a, stack_b, stack_a->arr_num);
	return (0);
}

void	init_stack(t_stack *stack, int *arr_num)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->num = 0;
	stack->stack_type = STACK_A;
	stack->arr_num = arr_num;
	stack->low_num = 0;
}

static int	*arg_to_arri(int *arr_len, char *arg)
{
	int i;
	char **temp;
	int *arr_num;

	i = -1;
	*arr_len = 0;
	temp = ft_split(arg, ' ');
	while (temp[*arr_len])
		(*arr_len)++;
	arr_num = ft_malloc(sizeof(int) * (*arr_len));
	while (++i < *arr_len)
		arr_num[i] = ft_atoi(temp[i]);
	ft_free(temp, 0, 1);
	return (arr_num);
}

static int *av_to_arri(int ac, char **av, int *arr_len)
{
	int i;
	int *arr_num;

	arr_num = ft_malloc(sizeof(int) * (ac - 1));
	i = -1;
	*arr_len = ac - 1;
	while (++i < ac - 1)
		arr_num[i] = ft_atoi(av[i + 1]);
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
	if (ac == 2)
		arr_num = arg_to_arri(&arr_len, av[1]);
	else
		arr_num = av_to_arri(ac, av, &arr_len);
	init_stack(&stack_a, arr_num);
	init_stack(&stack_b, arr_num);
	start_sort(&stack_a, &stack_b, arr_len);
	return (0);
}
