/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:36:50 by mchae             #+#    #+#             */
/*   Updated: 2020/10/14 16:47:13 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t input_size)
{
	size_t index;

	index = 0;
	if (!dest && !src)
		return (0);
	while (src[index] && index + 1 < input_size)
	{
		dest[index] = src[index];
		index++;
	}
	if (input_size != 0)
		dest[index] = 0;
	while (src[index])
		index++;
	return (index);
}
