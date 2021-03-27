/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:50 by mchae             #+#    #+#             */
/*   Updated: 2021/03/27 20:11:40 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	parsing_map_info(t_info *info, t_tex_info *tex_info)
{
	char	*tmp;
	int		i;

	i = -1;
	tmp = ft_strchr(info->info_map[RESOLUTION], ' ');
	invalid_char_error(tmp, RESOLUTION);
	info->screen_width = ft_atoi(tmp);
	tmp = ft_strrchr(info->info_map[RESOLUTION], ' ');
	info->screen_height = ft_atoi(tmp);
	while (++i <= SPRITE)
	{
		tmp = ft_strrchr(info->info_map[i], ' ') + 1;
		tex_info[i].texture_path = ft_strdup(tmp);
	}
	parsing_color(info, FLOOR_COLOR);
	parsing_color(info, CEILING_COLOR);
	i = -1;
	while (++i <= CEILING_COLOR)
		free(info->info_map[i]);
}

void	parsing_color(t_info *info, int type)
{
	int		i;
	int		j;
	char	*tmp;
	char	**tmp_split;
	int		temp_color[3];

	tmp = ft_strchr(info->info_map[type], ' ');
	invalid_char_error(tmp, type);
	tmp_split = ft_split(tmp, ',');
	i = -1;
	j = 0;
	while (tmp_split[j])
		j++;
	if (j != 3)
		error_exit("color over count");
	while (++i < 3)
		temp_color[i] = ft_atoi(tmp_split[i]);
	var_free(tmp_split, 0, 1);
	tmp_split = 0;
	get_color(temp_color, &info->color[type - 6]);
}

void	get_color(int *temp_color, int *color)
{
	int i;

	i = -1;
	*color = 0;
	while (++i < 3)
	{
		if (temp_color[i] > 255 || temp_color[i] < 0)
			error_exit("color over value");
		*color = (*color << 8) + temp_color[i];
	}
}
