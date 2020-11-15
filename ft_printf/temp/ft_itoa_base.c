/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:13:28 by mchae             #+#    #+#             */
/*   Updated: 2020/11/15 17:24:50 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*g_hex = "0123456789abcdef";
char	*g_upperhex = "0123456789ABCDEF";
int		g_i = 0;

static char	*conversion(char *str, size_t num, char format, int div_num)
{
	if (num == 0)
		g_i++;
	if (num / div_num)
	{
		g_i++;
		str = conversion(str, num / div_num, format, div_num);
	}
	if (!(num / div_num))
	{
		str = malloc(g_i + 1);
		str[g_i] = '\0';
	}
	if (format == 'X')
		*str = g_upperhex[num % div_num];
	else
		*str = g_hex[num % div_num];
	return (++str);
}

char		*ft_itoa_base(size_t num, char format, int div_num)
{
	char	*str;

	str = 0;
	if ((format == 'd' || format == 'i') && num & 1 << 31)
	{
		conversion(str, (size_t)((unsigned int)num * -1), format, div_num);
		return (str);
	}
	conversion(str, num, format, div_num);
	return (str);
}
