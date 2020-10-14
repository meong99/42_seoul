/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:30:48 by mchae             #+#    #+#             */
/*   Updated: 2020/10/14 16:41:41 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src,
					int input_char, size_t input_size)
{
	while (input_size--)
	{
		*(char*)dest++ = *(char*)src;
		if (*(unsigned char*)src++ == (unsigned char)input_char)
			return (dest);
	}
	return (0);
}
