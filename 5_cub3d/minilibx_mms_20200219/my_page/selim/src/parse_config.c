/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selim <selim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:03:09 by selim             #+#    #+#             */
/*   Updated: 2021/02/03 15:03:11 by selim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	g_fd;
int	g_ret;
int	g_type;

static int	check_map_element(char *line, const char *str)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (ft_strchr(str, line[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

static int	config_type(char *line)
{
	if (ft_strncmp(line, "R ", 2) == 0)
		return (C_R);
	else if (ft_strncmp(line, "NO ", 3) == 0)
		return (C_NO);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (C_SO);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (C_WE);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (C_EA);
	else if (ft_strncmp(line, "S ", 2) == 0)
		return (C_S);
	else if (ft_strncmp(line, "F ", 2) == 0)
		return (C_F);
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (C_C);
	else if (check_map_element(line, "012NSEW "))
		return (C_MAP);
	return (-1);
}

static int	is_blank_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!is_space(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int			parse_config(t_game *game, t_config *config, char const *conf_path)
{
	char			*line;

	if (!(is_endswith(conf_path, ".cub")))
		return (exit_error(game, EXIT_FAILURE, "Not .cub extension"));
	if ((g_fd = open(conf_path, O_RDONLY)) < 0)
		return (exit_error(game, EXIT_FAILURE, "Wrong file path"));
	g_ret = 1;
	while ((g_ret = get_next_line(g_fd, &line)) > 0)
	{
		if ((g_type = config_type(line)) == -1)
			return (exit_error(game, EXIT_FAILURE, "Wrong type"));
		if (is_blank_line(line) && !config->istype[C_MAP])
		{
			free(line);
			continue;
		}
		else if (is_blank_line(line) && config->istype[C_MAP])
			return (exit_error(game, EXIT_FAILURE, "Blank line in the map"));
		if (!parse_line(g_ret, config, g_type, line))
			return (exit_error(game, EXIT_FAILURE, "Parse line error"));
	}
	if (!parse_line(g_ret, config, g_type, line))
		return (exit_error(game, EXIT_FAILURE, "Parse line error"));
	close(g_fd);
	return (1);
}
