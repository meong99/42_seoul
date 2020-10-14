/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:38:53 by mchae             #+#    #+#             */
/*   Updated: 2020/10/14 16:44:04 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *input_arr, int input_char, size_t input_size)
{
	size_t i;

	i = 0;
	while (i < input_size)
	{
		((unsigned char *)input_arr)[i] = (unsigned char)input_char;
		i++;
	}
	return (input_arr);
}
