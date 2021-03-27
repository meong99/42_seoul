/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:54 by mchae             #+#    #+#             */
/*   Updated: 2021/03/27 20:12:07 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		count_element(char **element)
{
	int i;

	i = 0;
	while (*element)
	{
		i++;
		element++;
	}
	return (i);
}

void	error_exit(char *massege)
{
	printf("Error\n");
	printf("%s\n", massege);
	exit(-1);
}

double	get_radian(int angle)
{
	return (angle * (M_PI / 180));
}

int		color_div(int color, double perp_wall_dist)
{
	int		red;
	int		green;
	int		blue;

	red = color & 0xFF0000;
	green = color & 0x00FF00;
	blue = color & 0x0000FF;

	red -= ((int)perp_wall_dist & 0xFF0000) * 10;
	green -= ((int)perp_wall_dist & 0x00FF00) * 10;
	blue -= ((int)perp_wall_dist & 0x0000FF) * 10;
	color = 0;
	color |= red;
	color |= green;
	color |= blue;
	return (color);
}
