/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:33:43 by mchae             #+#    #+#             */
/*   Updated: 2020/10/23 14:33:57 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char *temp_dest;

	temp_dest = (char*)dest;
	if (!dest && !src)
		return (0);
	if ((dest > src && src + len > dest))
	{
		temp_dest += len;
		src += len;
		while (len--)
			*--temp_dest = *(char*)--src;
	}
	else
		while (len--)
			*temp_dest++ = *(char*)src++;
	return (dest);
}
