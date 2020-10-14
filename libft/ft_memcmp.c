/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:16:46 by mchae             #+#    #+#             */
/*   Updated: 2020/10/14 17:19:26 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str_1, const void *str_2, size_t input_size)
{
	while (input_size--)
	{
		if (*(unsigned char*)str_1 > *(unsigned char*)str_2)
			return (*(unsigned char*)str_1 - *(unsigned char*)str_2);
		else if (*(unsigned char*)str_1 < *(unsigned char*)str_2)
			return (*(unsigned char*)str_1 - *(unsigned char*)str_2);
		str_1++;
		str_2++;
	}
	return (0);
}
