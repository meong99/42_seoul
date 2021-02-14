/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selim <selim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:00:35 by selim             #+#    #+#             */
/*   Updated: 2020/10/07 16:48:36 by selim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t size_dest;
	size_t size_src;

	size_dest = ft_strlen(dest);
	size_src = ft_strlen(src);
	if (size == 0)
		return (size_src);
	i = size_dest;
	j = 0;
	if (size_dest <= size)
	{
		j = 0;
		while (src[j] != '\0' && i + 1 < size)
			dest[i++] = src[j++];
		dest[i] = '\0';
	}
	if (size_dest <= size)
		return (size_dest + size_src);
	else
		return (size_src + size);
}
