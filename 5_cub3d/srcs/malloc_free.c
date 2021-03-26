/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 14:46:39 by mchae             #+#    #+#             */
/*   Updated: 2021/03/26 13:14:23 by mchae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	var_free(void *var, int pointer_num, int index, int is_char)
{
	int i;

	i = -1;
	if (pointer_num == 1)
	{
		free(*((void**)var));
		*((void**)var) = 0;
	}
	else
	{
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
}

void	*var_malloc(size_t size)
{
	void	*var;

	var = ft_calloc(1, size);
	if (!var)
		error_exit("malloc error");
	return (var);
}

void	all_free(t_game *game)
{
	var_free(&game->sprite_dist, 1, game->info.sprite_num, 0);
	var_free(game->ray.buf, 2, game->info.screen_height, 0);
	var_free(&game->info.rows, 1, 0, 0);
	var_free(game->info.map, 2, 0, 1);
	var_free(game->info.map_mask, 2, game->info.cols, 0);
}
