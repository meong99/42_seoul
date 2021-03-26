/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:43 by mchae             #+#    #+#             */
/*   Updated: 2021/03/26 14:46:45 by mchae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	element_count_error(t_info *info)
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
		var_free(temp, 0, 1);
		temp = 0;
	}
}

void	screen_size_error(t_info *info)
{
	mlx_get_screen_size(info->mlx, &info->max_screen_width, \
		&info->max_screen_height);
	if (info->screen_width > info->max_screen_width)
		info->screen_width = info->max_screen_width;
	if (info->screen_height > info->max_screen_height)
		info->screen_height = info->max_screen_height;
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
