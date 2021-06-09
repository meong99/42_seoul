/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:30:47 by mchae             #+#    #+#             */
/*   Updated: 2021/06/09 19:10:42 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free(void *var, int index, int is_char)
{
	int i;

	i = -1;
	if (is_char)
	{
		while (((char**)var)[index++])
			;
	}
	while (++i < index)
	{
		free(((void**)var)[i]);
		((void**)var)[i] = 0;
	}
	free(var);
	return (0);
}
