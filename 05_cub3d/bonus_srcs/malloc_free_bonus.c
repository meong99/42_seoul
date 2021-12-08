/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_free_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 14:46:39 by mchae             #+#    #+#             */
/*   Updated: 2021/03/28 01:34:30 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	var_free(void *var, int index, int is_char)
{
	int i;

	i = -1;
	if (is_char)
	{
		while (((char**)var)[index++])
			;
	}
	while (++i < index)
	{
		free(((void**)var)[i]);
	}
	free(var);
}

void	*var_malloc(size_t size)
{
	void	*val;

	val = ft_calloc(1, size);
	if (!val)
		error_exit("malloc error");
	return (val);
}

void	all_free(t_game *game)
{
	free(game->sprite_dist);
	var_free(game->ray.buf, game->info.screen_height, 0);
	free(game->info.rows);
	free(game->ray.sprite_buf);
	var_free(game->info.map, 0, 1);
	var_free(game->info.map_mask, game->info.cols, 0);
}
