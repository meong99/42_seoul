/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selim <selim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:46:28 by selim             #+#    #+#             */
/*   Updated: 2021/02/03 22:27:58 by selim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			is_endswith(char const *conf_path, char const *str)
{
	int ret;
	int len;

	ret = 1;
	len = ft_strlen(conf_path);
	if (len >= 4)
		ret = ft_strncmp(conf_path + len - 4, str, 4);
	return (ret == 0 ? 1 : 0);
}

int			digit_check(char *str)
{
	int j;

	j = -1;
	while (str[++j])
	{
		if (!ft_isdigit(str[j]))
			return (0);
	}
	return (1);
}

int			check_rgb_range(char **rgb)
{
	int i;
	int tmp;

	i = 0;
	while (i < 3)
	{
		tmp = ft_atoi(rgb[i]);
		if (tmp < 0 || tmp > 255)
			return (0);
		i++;
	}
	return (1);
}
