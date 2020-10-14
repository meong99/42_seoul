/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 13:30:33 by mchae             #+#    #+#             */
/*   Updated: 2020/10/14 16:29:06 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t input_count, size_t input_size)
{
	void	*result_allocation;
	size_t	i;

	i = 0;
	if (!(result_allocation = malloc(input_size * input_count)))
		return (0);
	ft_memset(result_allocation, 0, input_size * input_count);
	return (result_allocation);
}
