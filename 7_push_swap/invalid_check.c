/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:29:24 by mchae             #+#    #+#             */
/*   Updated: 2021/06/09 19:05:26 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	overlap_check(int *arr_num, int arr_len)
{
	int check;
	int i;
	int j;

	i = -1;
	while (++i < arr_len)
	{
		check = arr_num[i];
		j = i;
		while (++j < arr_len)
		{
			if (check == arr_num[j])
			{
				write(1, "Error\n", 6);
				exit(-1);
			}
		}
	}
	return (1);
}
