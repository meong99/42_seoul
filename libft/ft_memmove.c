/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:33:43 by mchae             #+#    #+#             */
/*   Updated: 2020/10/14 16:43:15 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t input_size)
{
	void *temp_dest;

	temp_dest = dest;
	if (!dest && !src)
		return (0);
	if ((dest > src && src + input_size > dest))
	{
		temp_dest += input_size;
		src += input_size;
		while (input_size--)
			*(char*)--temp_dest = *(char*)--src;
	}
	else
		while (input_size--)
			*(char*)temp_dest++ = *(char*)src++;
	return (dest);
}
