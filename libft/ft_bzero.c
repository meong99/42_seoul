/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:43:31 by mchae             #+#    #+#             */
/*   Updated: 2020/10/14 16:23:54 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *input_str, size_t input_size)
{
	size_t i;

	i = 0;
	while (i < input_size)
	{
		((unsigned char *)input_str)[i] = 0;
		i++;
	}
}
