/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:02:52 by mchae             #+#    #+#             */
/*   Updated: 2020/10/22 20:16:41 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t j;
	size_t i;

	j = 0;
	i = 0;
	while (dest[i])
	{
		i++;
	}
	while (src[j] && i + j + 1 < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	while (src[j])
		j++;
	if (size < i)
		return (j + size);
	else
		return (i + j);
}
