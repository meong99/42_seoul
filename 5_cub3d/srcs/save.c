/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:02:14 by mchae             #+#    #+#             */
/*   Updated: 2021/03/19 03:17:45 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		int_to_char(int size, unsigned char *bmp_header)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		bmp_header[i] = (unsigned char)size;
		size >>= 8;
	}
}

static int		bit_header_set(int fd, t_game *game)
{
	int				ret;
	int				i;
	unsigned char	bmp_header[54];

	i = 1;
	ft_bzero(bmp_header, 54);
	bmp_header[0] = 'B';
	bmp_header[1] = 'M';
	int_to_char(54 + (game->info.screen_width + game->img.padding) \
		* game->info.screen_height, bmp_header + 2);
	bmp_header[10] = (unsigned char)54;
	bmp_header[14] = (unsigned char)40;
	int_to_char(game->info.screen_width + game->img.padding, bmp_header + 18);
	int_to_char(game->info.screen_height, bmp_header + 22);
	bmp_header[26] = (unsigned char)1;
	bmp_header[28] = (unsigned char)24;
	ret = write(fd, bmp_header, 54);
	if (ret < 0)
		error_exit("screenshot write error");
	return (ret);
}

static void		write_bmp_data_pixel(int fd, t_game *game)
{
	int				i;
	int				j;
	int				color;

	i = game->info.screen_height - 1;
	while (--i > 0)
	{
		j = -1;
		while (++j < game->info.screen_width)
		{
			color = game->img.data[(game->info.screen_width + game->img.padding) * i + j];
			if (write(fd, &color, 3) < 0)
				error_exit("color write error");
		}
	}
}

void			save_bmp(t_game *game)
{
	int					fd;

	fd = open("screenshot.bmp", O_RDWR | O_CREAT, 0600);
	if (fd < 0)
		error_exit("bmp open error");
	raycasting(game);
	bit_header_set(fd, game);
	write_bmp_data_pixel(fd, game);
	close(fd);
	exit(0);
}
