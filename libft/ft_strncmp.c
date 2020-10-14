/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:38:54 by mchae             #+#    #+#             */
/*   Updated: 2020/10/14 16:47:59 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str_1, const char *str_2, size_t input_size)
{
	size_t i;

	i = 0;
	while ((str_1[i] || str_2[i]) && i < input_size)
	{
		if (str_1[i] > str_2[i])
			return (((unsigned char*)str_1)[i] - ((unsigned char*)str_2)[i]);
		else if (str_1[i] < str_2[i])
			return (((unsigned char*)str_1)[i] - ((unsigned char*)str_2)[i]);
		i++;
	}
	return (0);
}
