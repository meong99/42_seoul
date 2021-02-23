/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:50 by mchae             #+#    #+#             */
/*   Updated: 2021/02/23 19:51:42 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing_map_info(t_game *game)
{
	char	*tmp;

	tmp = ft_strchr(game->info_map[RESOLUTION], ' ');
	invalid_char_error(tmp, RESOLUTION);
	game->resolution[0] = ft_atoi(tmp);
	tmp = ft_strrchr(game->info_map[RESOLUTION], ' ');
	game->resolution[1] = ft_atoi(tmp);
	tmp = ft_strrchr(game->info_map[NORTH], ' ');
	game->north_texture = ft_strdup(tmp);
	tmp = ft_strrchr(game->info_map[SOUTH], ' ');
	game->south_texture = ft_strdup(tmp);
	tmp = ft_strrchr(game->info_map[WEST], ' ');
	game->west_texture = ft_strdup(tmp);
	tmp = ft_strrchr(game->info_map[EAST], ' ');
	game->east_texture = ft_strdup(tmp);
	tmp = ft_strrchr(game->info_map[SPRITE], ' ');
	game->sprite_texture = ft_strdup(tmp);
	parsing_color(game, FLOOR_COLOR, game->floor_color);
	parsing_color(game, CEILING_COLOR, game->ceiling_color);
}

void	parsing_color(t_game *game, int type, int *p_color)
{
	int		i;
	int		j;
	char	*tmp;
	char	**tmp_split;

	tmp = ft_strchr(game->info_map[type], ' ');
	invalid_char_error(tmp, type);
	tmp_split = ft_split(tmp, ',');
	i = -1;
	j = 0;
	while (tmp_split[j])
		j++;
	if (j != 3)
		error_exit("color over count");
	while (++i < 3)
		p_color[i] = ft_atoi(tmp_split[i]);
	val_free(tmp_split, 2);
}
