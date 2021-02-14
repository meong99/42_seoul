/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selim <selim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:40:32 by selim             #+#    #+#             */
/*   Updated: 2021/02/04 13:23:41 by selim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		exit_error(t_game *game, int code, char const *str)
{
	write(1, "Error\n", 6);
	if (str)
		write(1, str, ft_strlen(str));
	exit(code);
	if (game->config.rows)
		free_machine(game);
	return (0);
}

int		exit_error_line(char *line, int code, char const *str)
{
	write(1, "Error\n", 6);
	if (str)
		write(1, str, ft_strlen(str));
	free(line);
	exit(code);
	return (0);
}

int		exit_game(t_game *game)
{
	free_machine(game);
	stop_music();
	exit(0);
	return (0);
}
