/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selim <selim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:59:53 by selim             #+#    #+#             */
/*   Updated: 2021/02/04 19:02:18 by selim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		play_music(char *str)
{
	str += 0;
	system("afplay -v 0.30  music/underthesea.mp3 &");
}

void		stop_music(void)
{
	system("killall afplay");
}

void		show_info(t_game *game)
{
	char	*msg;
	char	*tmp;
	char	*num;

	num = ft_itoa(game->player.move_speed * 100);
	msg = ft_strjoin("Move Speed : ", num);
	mlx_string_put(game->mlx, game->win, game->config.screenwidth \
		- 150, game->config.screenheight - 50, 0xFFFFFF, msg);
	free(msg);
	free(num);
	num = ft_itoa(3 - (game->config.sprite_num - 1));
	tmp = ft_strjoin("number of ", num);
	msg = ft_strjoin(tmp, " fish yum!!");
	mlx_string_put(game->mlx, game->win, 20, \
		game->config.screenheight - 50, 0xFFFFFF, msg);
	free(num);
	free(tmp);
	free(msg);
}
