/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:02:52 by mchae             #+#    #+#             */
/*   Updated: 2020/10/15 01:29:26 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t input_size)
{
	size_t src_index;
	size_t dest_index;

	src_index = 0;
	dest_index = 0;
	while (dest[dest_index])
	{
		dest_index++;
	}
	while (src[src_index] && dest_index + src_index + 1 < input_size)
	{
		dest[dest_index + src_index] = src[src_index];
		src_index++;
	}
	dest[dest_index + src_index] = '\0';
	while (src[src_index])
		src_index++;
	if (input_size < dest_index)
		return (src_index + input_size);
	else
		return (dest_index + src_index);
}
