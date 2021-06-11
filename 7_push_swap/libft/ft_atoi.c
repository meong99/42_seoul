/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 11:45:55 by mchae             #+#    #+#             */
/*   Updated: 2021/06/11 15:49:21 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	error_check(const char *str)
{
	int				i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
		{
			write(1, "Error\n", 6);
			exit(-1);
		}
	}
}

static void	overflow_check(int sign, int result, int strlen)
{
	int result_len;

	result_len = 0;
	if ((sign > 0 && result < 0) ||\
		(sign < 0 && result > 0))
	{
		write(1, "Error\n", 6);
		exit(-1);
	}
	while (result)
	{
		result_len++;
		result /= 10;
	}
	if (result_len != strlen && result)
	{
		write(1, "Error\n", 6);
		exit(-1);
	}
}

int			ft_atoi(const char *str)
{
	unsigned int	result;
	int				sign;
	int				strlen;

	sign = 1;
	result = 0;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	error_check(str);
	strlen = ft_strlen(str);
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str++ - '0';
	}
	overflow_check(sign, result * sign, strlen);
	return (result * sign);
}
