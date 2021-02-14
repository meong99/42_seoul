/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selim <selim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:05:55 by selim             #+#    #+#             */
/*   Updated: 2021/02/04 13:25:05 by selim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	int_to_char(int n, unsigned char *src)
{
	src[0] = (unsigned char)n;
	src[1] = (unsigned char)(n >> 8);
	src[2] = (unsigned char)(n >> 16);
	src[3] = (unsigned char)(n >> 24);
}

static int	write_bmp_header(int fd, int file_size, t_game *game)
{
	int				ret;
	unsigned char	bmp_header[54];

	ft_bzero(bmp_header, 54);
	bmp_header[0] = (unsigned char)('B');
	bmp_header[1] = (unsigned char)('M');
	int_to_char(file_size, bmp_header + 2);
	bmp_header[10] = (unsigned char)54;
	bmp_header[14] = (unsigned char)40;
	int_to_char(game->config.screenwidth, bmp_header + 18);
	int_to_char(game->config.screenheight, bmp_header + 22);
	bmp_header[26] = (unsigned char)1;
	bmp_header[28] = (unsigned char)24;
	ret = write(fd, bmp_header, 54);
	return (ret);
}

static int	get_color(t_game *game, int x, int y)
{
	int			color;
	int			rgb;

	color = game->img.data[game->config.screenwidth * y + x];
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (rgb);
}

static int	write_bmp_data_pixel(int fd, int pad, t_game *game)
{
	int				i;
	int				j;
	int				color;
	unsigned char	zero[3];

	i = -1;
	while (++i < 3)
		zero[i] = (unsigned char)0;
	i = game->config.screenheight - 1;
	while (--i > 0)
	{
		j = -1;
		while (++j < game->config.screenwidth)
		{
			color = get_color(game, j, i);
			if (write(fd, &color, 3) < 0)
				return (0);
			if (pad > 0 && write(fd, &zero, pad) < 0)
				return (0);
		}
	}
	return (1);
}

int			screenshot(t_game *game)
{
	int		fd;
	int		file_size;
	int		pixel_bytes_per_row;
	int		pad;

	draw_ceil_floor(game);
	calc_raycasting(game);
	calc_sprite(game);
	draw(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	pixel_bytes_per_row = game->config.screenwidth * 3;
	pad = (4 - pixel_bytes_per_row % 4) % 4;
	file_size = 54 + 3 * (game->config.screenwidth + pad)\
				* game->config.screenheight;
	if ((fd = open("screenshot.bmp", O_RDWR | O_CREAT | O_TRUNC, 0644)) < 0)
		return (exit_error(game, EXIT_FAILURE, "ERROR\nbmp open failure"));
	if (!(write_bmp_header(fd, file_size, game)) ||
			!(write_bmp_data_pixel(fd, pad, game)))
		return (exit_error(game, EXIT_FAILURE, "ERROR\nbmp write failure"));
	close(fd);
	return (1);
}
