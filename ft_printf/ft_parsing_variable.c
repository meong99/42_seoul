/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_variable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:26:13 by mchae             #+#    #+#             */
/*   Updated: 2020/11/19 21:50:20 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parsing_varialbe_str(char *str, t_info *info)
{
	if (!str)
		info->variable = ft_strdup("(null)");
	else
		info->variable = ft_strdup(str);
}

void	parsing_varialbe_integer(long number, t_info *info)
{
	int my_switch;

	my_switch = get_va_datatype(number, info);
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
	if (number == 0 && info->bonus_flasg == '#')
		info->bonus_flasg = 0;
}

int		get_va_datatype(int number, t_info *info)
{
	int datatype;

	if (info->bonus_format)
		datatype = 1;
	else
		datatype = 2;
	return (datatype);
}

void	parsing_varialbe_char(char c, t_info *info)
{
	info->variable = (char*)malloc(2);
	ft_strlcpy(info->variable, &c, 2);
	info->precision = 0;
	info->dot = 0;
}

void	parsing_varialbe_pointer(size_t pointer, t_info *info)
{
	info->bonus_flasg = '#';
	info->variable = ft_itoa_base(pointer, info->format, 16);
	if (!pointer && info->dot)
		*info->variable = 0;
}
