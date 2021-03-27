/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:54 by mchae             #+#    #+#             */
/*   Updated: 2021/03/27 20:14:23 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
