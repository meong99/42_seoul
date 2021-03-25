/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaemyeongseog <chaemyeongseog@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 14:46:39 by mchae             #+#    #+#             */
/*   Updated: 2021/03/22 16:51:16 by chaemyeongs      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	var_free(void *var, int pointer_num, int index, int is_char)
{
	int i;

	i = -1;
	if (pointer_num == 1)
	{
		free(*((void**)var));
		*((void**)var) = 0;
	}
	else
	{
		if (is_char)
		{
			while (((char**)var)[index++])
				;
		}
		while (++i < index)
		{
			free(((void**)var)[i]);
		}
		free(var);
	}
}

void	*var_malloc(size_t size)
{
	void	*val;

	val = ft_calloc(1, size);
	if (!val)
		error_exit("malloc error");
	return (val);
}
