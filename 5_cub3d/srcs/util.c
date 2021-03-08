/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:54 by mchae             #+#    #+#             */
/*   Updated: 2021/03/08 15:36:34 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		*todigit(t_game *game, char *s, int index)
{
	int	*new_str;
	int	i;

	if (!s)
		return (NULL);
	i = -1;
	game->rows[index] = ft_strlen(s);
	if (!(new_str = (int*)val_malloc(sizeof(int) * game->rows[index])))
		return (NULL);
	while (s[++i])
		new_str[i] = s[i] - '0';
	return (new_str);
}

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
