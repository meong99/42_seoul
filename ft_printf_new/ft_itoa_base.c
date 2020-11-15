/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:13:28 by mchae             #+#    #+#             */
/*   Updated: 2020/11/15 20:39:18 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *g_hex = "0123456789abcdef";
char *g_upperhex = "0123456789ABCDEF";

static char	*conversion(char *str, size_t num, char format, int div_num)
{
	if (num / div_num)
		str = conversion(str, num / div_num, format, div_num);
	if (format == 'X')
		*str = g_upperhex[num % div_num];
	else
		*str = g_hex[num % div_num];
	return (++str);
}

static int	get_len(size_t num, int div_num)
{
	int				len;

	len = 0;
	while (num)
	{
		num /= div_num;
		len++;
	}
	return (len);
}

char		*ft_itoa_base(size_t num, char format, int div_num)
{
	char	*str;
	int		len;

	if ((format == 'd' || format == 'i') && num & 1 << 31)
		len = get_len((size_t)((unsigned int)num * -1), div_num);
	else
		len = get_len(num, div_num);
	if (num == 0)
		len++;
	str = malloc(len + 1);
	str[len] = '\0';
	if ((format == 'd' || format == 'i') && num & 1 << 31)
	{
		conversion(str, (size_t)((unsigned int)num * -1), format, div_num);
		return (str);
	}
	conversion(str, num, format, div_num);
	return (str);
}
