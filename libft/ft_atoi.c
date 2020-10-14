/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 11:45:55 by mchae             #+#    #+#             */
/*   Updated: 2020/10/14 17:07:14 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *input_str)
{
	unsigned int	result_num;
	int				sign;

	sign = 1;
	result_num = 0;
	while ((*input_str >= 9 && *input_str <= 13) || *input_str == ' ')
		input_str++;
	if (*input_str == '-' || *input_str == '+')
		if (*input_str++ == '-')
			sign *= -1;
	while (*input_str >= '0' && *input_str <= '9')
	{
		result_num *= 10;
		result_num += *input_str++ - '0';
		if (result_num > 2147483648 && sign == -1)
			return (0);
		if (result_num > 2147483647 && sign == 1)
			return (-1);
	}
	return (result_num * sign);
}
