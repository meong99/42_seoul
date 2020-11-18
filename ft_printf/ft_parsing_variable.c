/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_variable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:26:13 by mchae             #+#    #+#             */
/*   Updated: 2020/11/18 17:02:12 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parsing_varialbe_str(char *str, t_info *info)
{
	if (!str)
	{
		info->variable = (char*)malloc(7);
		ft_strlcpy(info->variable, "(null)", 7);
	}
	else
	{
		info->variable = (char*)malloc(ft_strlen(str) + 1);
		ft_strlcpy((char*)info->variable, str, ft_strlen(str) + 1);
	}
}

void	parsing_varialbe_integer(int number, t_info *info)
{
	if (info->format == 'd' || info->format == 'i' || info->format == 'u')
		info->variable = ft_itoa_base((size_t)(unsigned int)number,
						info->format, 10);
	else
		info->variable = ft_itoa_base((size_t)(unsigned int)number,
						info->format, 16);
	if (number < 0 && (info->format == 'd' || info->format == 'i'))
		info->minus = '-';
	else if (number == 0 && info->dot && !info->precision)
		*info->variable = 0;
	if (number == 0 && info->bonus_flasgs == '#')
		info->bonus_flasgs = 0;
}

void	parsing_varialbe_char(char c, t_info *info)
{
	info->variable = (char*)malloc(2);
	*info->variable = c;
	info->variable[1] = 0;
	info->precision = 0;
	info->dot = 0;
}

void	parsing_varialbe_pointer(size_t pointer, t_info *info)
{
	info->bonus_flasgs = '#';
	info->variable = ft_itoa_base(pointer, info->format, 16);
	if (!pointer && info->dot)
		*info->variable = 0;
}
