/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:43 by mchae             #+#    #+#             */
/*   Updated: 2021/02/26 20:21:32 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	info_error(t_game *game)
{
	element_count_error(game);
	screen_size_and_color_error(game);
}

void	element_count_error(t_game *game)
{
	char	**temp;
	int		i;

	i = -1;
	while (++i <= CEILING_COLOR)
	{
		temp = ft_split(game->info_map[i], ' ');
		if (i == 0 && count_element(temp) != 3)
			error_exit("resolution count error");
		else if (i != 0 && count_element(temp) != 2)
			error_exit("info count error");
		char_free(temp, 2);
	}
	parsing_map_info(game);
}

void	screen_size_and_color_error(t_game *game)
{
	int		i;
	int		resol_x;
	int		resol_y;

	i = -1;
	mlx_get_screen_size(game->mlx, &resol_x, &resol_y);
	if (game->screen_width > resol_x)
		game->screen_width = resol_x;
	if (game->screen_height > resol_y)
		game->screen_height = resol_y;
	while (++i < 3)
	{
		if (game->floor_color[i] > 255 || game->floor_color[i] < 0 ||
			game->ceiling_color[i] > 255 || game->ceiling_color[i] < 0)
			error_exit("color over value");
	}
}

int		overlap_error(t_game *game, int type)
{
	if (game->info_check[type] == type)
		error_exit("overlap error");
	else
		game->info_check[type] = type;
	return (type);
}

void	invalid_char_error(const char *info, int type)
{
	if (type == RESOLUTION)
	{
		while (*info)
		{
			if (*info != ' ' && !ft_isdigit(*info))
				error_exit("invalid char error");
			info++;
		}
	}
	else
	{
		while (*info)
		{
			if (*info != ' ' && *info != ',' && !ft_isdigit(*info))
				error_exit("invalid char error");
			info++;
		}
	}
}
