/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:23:24 by mchae             #+#    #+#             */
/*   Updated: 2021/03/27 20:11:04 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	load_xpm_image(t_tex_info *tex_info, t_info *info)
{
	if (!(tex_info->img =\
		mlx_xpm_file_to_image(info->mlx, tex_info->texture_path, \
		&tex_info->texture_width, &tex_info->texture_height)))
		error_exit("texture path error");
	tex_info->data = (int*)mlx_get_data_addr(tex_info->img, &tex_info->bpp, \
		&tex_info->size_l, &tex_info->endian);
}

void	draw_image(t_info *info, t_img *img, t_ray *ray)
{
	int		i;
	int		j;

	i = -1;
	while (++i < info->screen_height)
	{
		j = -1;
		while (++j < info->screen_width)
			img->data[(info->screen_width + img->padding) * i + j] = \
			ray->buf[i][j];
	}
	mlx_put_image_to_window(info->mlx, info->win, img->img, 0, 0);
}

void	draw_fl_cei(t_info *info, t_ray *ray, t_player *player)
{
	int		i;
	int		j;

	i = -1;
	while (++i < info->screen_height)
	{
		j = -1;
		while (++j < info->screen_width)
		{
			if (i < info->screen_height / 2 + player->eye_level)
				ray->buf[i][j] = info->color[CEILING];
			else
				ray->buf[i][j] = info->color[FLOOR];
		}
	}
}
