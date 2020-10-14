/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:10:24 by mchae             #+#    #+#             */
/*   Updated: 2020/10/14 16:45:59 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *input_str)
{
	int		i;
	char	*result_copy;

	i = 0;
	if (!(result_copy = (char *)malloc(ft_strlen(input_str) + 1)))
		return (0);

	while (input_str[i] != 0)
	{
		result_copy[i] = input_str[i];
		i++;
	}
	result_copy[i] = 0;
	return (result_copy);
}
