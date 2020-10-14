/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:06:51 by mchae             #+#    #+#             */
/*   Updated: 2020/10/14 16:38:32 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *input_str, int input_char, size_t input_size)
{
	unsigned char *temp_str;

	temp_str = (unsigned char *)input_str;
	while (input_size--)
	{
		if (*temp_str++ == (unsigned char)input_char)
			return (&*--temp_str);
	}
	return (0);
}
