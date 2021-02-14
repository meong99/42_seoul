/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selim <selim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 10:34:34 by selim             #+#    #+#             */
/*   Updated: 2020/10/08 17:27:20 by selim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_whitespace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	an;
	unsigned long	bor;

	an = 0;
	sign = 1;
	bor = 922337203685477580;
	i = 0;
	while (str[i] && is_whitespace(str[i]))
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if ((an > bor || (an == bor && (str[i] - '0') > 7)) && sign == 1)
			return (-1);
		else if ((an > bor || (an == bor && (str[i] - '0') > 8)) && sign == -1)
			return (0);
		an = an * 10 + (unsigned long int)(str[i] - '0');
		i++;
	}
	return ((int)sign * an);
}
