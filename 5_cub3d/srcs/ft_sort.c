/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:16:16 by mchae             #+#    #+#             */
/*   Updated: 2021/03/14 16:16:31 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	swap_value(int *value_1, int *value_2)
{
	int temp;

	temp = *value_1;
	*value_1 = *value_2;
	*value_2 = temp;
}

int		partition(void *value, int left_index, int right_index)
{
	t_sprite_dist	*sprite_dist;
	int				i;
	int				j;

	sprite_dist = (t_sprite_dist*)value;
	i = left_index - 1;
	j = left_index - 1;
	while (++j < right_index)
	{
		if (sprite_dist[j].dist < sprite_dist[right_index].dist)
		{
			i++;
			swap_value(&sprite_dist[i].dist, &sprite_dist[j].dist);
		}
	}
	swap_value(&sprite_dist[--j].dist, &sprite_dist[right_index].dist);
	return (j);
}

void	quick_sort(void *value, int left_index, int right_index)
{
	int				pivot;

	if (left_index < right_index)
	{
		pivot = partition(value, left_index, right_index);
		quick_sort(value, left_index, pivot - 1);
		quick_sort(value, pivot + 1, right_index);
	}
}
