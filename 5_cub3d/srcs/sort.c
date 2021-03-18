/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:16:16 by mchae             #+#    #+#             */
/*   Updated: 2021/03/18 13:44:23 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	swap_value(t_sprite_dist **value, int index_1, int index_2)
{
	t_sprite_dist	temp;

	temp = (*value)[index_1];
	(*value)[index_1] = (*value)[index_2];
	(*value)[index_2] = temp;
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
		if (sprite_dist[j].dist > sprite_dist[right_index].dist)
		{
			i++;
			swap_value(&sprite_dist, i, j);
		}
	}
	swap_value(&sprite_dist, i + 1, right_index);
	return (i + 1);
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
