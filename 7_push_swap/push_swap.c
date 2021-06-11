/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:56:10 by mchae             #+#    #+#             */
/*   Updated: 2021/06/11 16:37:33 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		while (++j < n)
		{
			if (arr_num[j] < arr_num[least])
				least = j;
		}
		if (i != least)
		{
			temp = arr_num[i];
			arr_num[i] = arr_num[least];
			arr_num[least] = temp;
		}
	}
}

static void	atoi_free_temp(char ***temp, int *arr_num)
{
	int i;
	int j;
	int k;

	i = -1;
	k = -1;
	while (temp[++i])
	{
		j = -1;
		while (temp[i][++j])
			arr_num[++k] = ft_atoi(temp[i][j]);
	}
	i = -1;
	while (temp[++i])
	{
		ft_free(temp[i], 0, TYPE_C);
		temp[i] = 0;
	}
	free(temp);
}

static int	*av_to_arri(int ac, char **av, int *arr_len)
{
	char	***temp;
	int		i;
	int		j;
	int		*arr_num;

	i = -1;
	*arr_len = 0;
	temp = ft_malloc(sizeof(char**) * (ac));
	temp[ac - 1] = 0;
	while (++i < ac - 1)
	{
		j = -1;
		temp[i] = ft_split(av[1 + i], ' ');
		if (temp[i] == 0 || !*temp[i])
		{
			write(1, "Error\n", 6);
			exit(-1);
		}
		while (temp[i][++j])
			(*arr_len)++;
	}
	arr_num = ft_malloc(sizeof(int) * *arr_len);
	atoi_free_temp(temp, arr_num);
	temp = 0;
	return (arr_num);
}

static int	start_sort(t_stack *stack_a, t_stack *stack_b, int num)
{
	create_list(stack_a, stack_a->arr_num, num);
	sort_arr_num(stack_a->arr_num, num);
	quick_sort(num, stack_a, stack_b);
	return (0);
}

int			main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		*arr_num;
	int		arr_len;
	int		low_num;

	if (ac < 2)
	{
		write(1, "Error\n", 6);
		exit(-1);
	}
	arr_num = av_to_arri(ac, av, &arr_len);
	low_num = 0;
	init_stack(&stack_a, arr_num, &low_num, STACK_A);
	init_stack(&stack_b, arr_num, &low_num, STACK_B);
	duplicate_check(arr_num, arr_len);
	start_sort(&stack_a, &stack_b, arr_len);
	return (0);
}
