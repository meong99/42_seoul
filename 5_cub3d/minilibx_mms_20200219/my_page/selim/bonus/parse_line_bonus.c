/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selim <selim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:43:38 by selim             #+#    #+#             */
/*   Updated: 2021/02/04 13:24:55 by selim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	get_screensize(t_config *config, char *line)
{
	int		i;
	char	**size;

	i = 0;
	if (config->screenheight || config->screenwidth)
		return (0);
	if (!(size = ft_split(line, ' ')))
		return (0);
	if (!size[0] || !size[1] || !size[2] || size[3])
		return (0);
	if (!digit_check(size[1]) || !digit_check(size[2]))
		return (0);
	config->screenwidth = ft_atoi(size[1]);
	config->screenheight = ft_atoi(size[2]);
	free_2stars(size);
	if (config->screenwidth > 2560)
		config->screenwidth = 2560;
	if (config->screenheight > 1440)
		config->screenheight = 1440;
	if (!config->screenwidth || !config->screenheight)
		return (0);
	return (1);
}

static int	get_path(t_config *config, char *line, int tp)
{
	int		i;
	char	*buff;

	if (config->tex[tp].tex_path)
		exit_error_line(line, EXIT_FAILURE, "Path error");
	i = 0;
	while (is_upper(line[i]))
		i++;
	while (is_space(line[i]))
		i++;
	buff = ft_strdup(line + i);
	config->tex[tp].tex_path = buff;
	return (1);
}

static int	get_color(t_config *config, char *line, int tp)
{
	char	**rgb;
	int		color;

	if (!(rgb = ft_split(line + 2, ',')))
		return (0);
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		return (0);
	if (!check_rgb_range(rgb))
		return (0);
	color = ((ft_atoi(rgb[0]) * 256) + ft_atoi(rgb[1])) * 256 + ft_atoi(rgb[2]);
	free_2stars(rgb);
	rgb = 0;
	if (tp == C_F)
	{
		config->floor_color = color;
	}
	else if (tp == C_C)
		config->ceiling_color = color;
	config->istype[tp]++;
	return (1);
}

static int	get_map(t_config *config, char *temp)
{
	int		i;
	int		j;

	if (!(config->map = ft_split(temp, '\n')))
		return (0);
	config->istype[C_MAP] = 1;
	free(temp);
	i = -1;
	j = 0;
	while (config->map[++i])
		j = j < (int)ft_strlen(config->map[i])
			? (int)ft_strlen(config->map[i]) : j;
	config->rows = i;
	config->colums = j;
	config->tile = config->screenwidth / config->colums;
	return (1);
}

int			parse_line(int ret, t_config *c, int tp, char *line)
{
	static char *temp = "";

	if (tp == C_R)
	{
		if (!get_screensize(c, line))
			return (exit_error_line(line, EXIT_FAILURE, "Screensize error"));
	}
	else if (tp >= C_NO && tp <= C_S)
		get_path(c, line, tp);
	else if (tp == C_F || tp == C_C)
	{
		if (!get_color(c, line, tp) || !get_color(c, line, tp))
			return (exit_error_line(line, EXIT_FAILURE, "Color error"));
	}
	else
	{
		temp = add_str_back(temp, line);
		c->istype[C_MAP] = 1;
	}
	if (ret == 0 && !get_map(c, temp))
		return (exit_error_line(line, EXIT_FAILURE, "Map parse error"));
	free(line);
	return (1);
}
