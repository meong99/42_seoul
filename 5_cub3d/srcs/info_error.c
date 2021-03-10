/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaemyeongseog <chaemyeongseog@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:43 by mchae             #+#    #+#             */
/*   Updated: 2021/03/10 17:54:34 by chaemyeongs      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	info_error(t_info *info, t_tex_info *tex_info)
{
	element_count_error(info, tex_info);
	screen_size_error(info);
}

void	element_count_error(t_info *info, t_tex_info *tex_info)
{
	char	**temp;
	int		i;

	i = -1;
	while (++i <= CEILING_COLOR)
	{
		temp = ft_split(info->info_map[i], ' ');
		if (i == RESOLUTION && count_element(temp) != 3)
			error_exit("resolution count error");
		else if (i != RESOLUTION && count_element(temp) != 2)
			error_exit("info count error");
		var_free(temp, 2, 0, TYPE_CHAR);
		free(temp);
	}
	parsing_map_info(info, tex_info);
}

void	screen_size_error(t_info *info)
{
	int		i;
	int		resol_x;
	int		resol_y;

	i = -1;
	mlx_get_screen_size(info->mlx, &resol_x, &resol_y);
	if (info->screen_width > resol_x)
		info->screen_width = resol_x;
	if (info->screen_height > resol_y)
		info->screen_height = resol_y;
}

int		overlap_error(t_info *info, int type)
{
	if (info->info_check[type] == type)
		error_exit("overlap error");
	else
		info->info_check[type] = type;
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
