/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 11:29:42 by mchae             #+#    #+#             */
/*   Updated: 2020/11/18 21:03:58 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	int		result;

	va_start(ap, str);
	result = start_printf(str, ap);
	va_end(ap);
	return (result);
}

int		start_printf(const char *str, va_list ap)
{
	t_info	info;
	int		result;

	result = 0;
	while (*str)
	{
		if (*str == '%')
		{
			initialization_info(&info);
			result += parsing_print(&str, ap, &info);
		}
		else
			result += ft_putchar_fd(*str++, 1);
	}
	return (result);
}

int		parsing_print(const char **str, va_list ap, t_info *info)
{
	(*str)++;
	parsing_flag(str, info);
	parsing_wid(str, ap, info);
	if (**str == '.')
	{
		info->dot++;
		(*str)++;
		parsing_pre(str, ap, info);
	}
	info->format = **str;
	if (**str)
		*str = (*str) + 1;
	if (info->format != 'X')
		info->format = ft_tolower(info->format);
	parsing_varialbe(ap, info);
	clean_up(info);
	return (print_conversions(info));
}

void	clean_up(t_info *info)
{
	if (info->flags == '0' && (info->sign == '-' ||
		(info->dot && info->precision >= 0)))
		info->flags = 0;
	else if (info->flags == '#' && info->format != 'x' &&
			info->format != 'X' && info->format != 'p')
		info->flags = 0;
	else if (info->flags == '+' && (info->format != 'd' && info->format != 'i'))
		info->flags = 0;
	else if (info->flags == ' ' && info->minus == '-')
		info->flags = 0;
	else if (info->dot && info->format == 's')
	{
		if (info->precision < (int)ft_strlen(info->variable))
			info->variable[info->precision] = 0;
		info->precision = 0;
	}
}

void	initialization_info(t_info *info)
{
	info->flags = 0;
	info->format = 0;
	info->precision = 0;
	info->sign = 0;
	info->width = 0;
	info->variable = 0;
	info->minus = 0;
	info->dot = 0;
	info->bonus_flasgs = 0;
}
