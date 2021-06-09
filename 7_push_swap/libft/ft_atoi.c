/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 11:45:55 by mchae             #+#    #+#             */
/*   Updated: 2021/06/09 19:28:21 by mchae            ###   ########.fr       */
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

int			ft_atoi(const char *str)
{
	unsigned int	result;
	int				sign;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	error_check(str);
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str++ - '0';
	}
	return (result * sign);
}
