/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 13:30:33 by mchae             #+#    #+#             */
/*   Updated: 2020/10/16 22:18:01 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t input_count, size_t input_size)
{
	void	*result_allocation;

	if (!(result_allocation = malloc(input_size * input_count)))
		return (0);
	ft_memset(result_allocation, 0, input_size * input_count);
	return (result_allocation);
}
