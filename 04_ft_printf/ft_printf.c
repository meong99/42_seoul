/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 11:29:42 by mchae             #+#    #+#             */
/*   Updated: 2020/11/23 18:47:34 by mchae            ###   ########.fr       */
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
	int		*n_pointer;

	result = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			initialization_info(&info);
			if (*str != 'n')
				result += parsing_print(&str, ap, &info);
			else
			{
				n_pointer = va_arg(ap, int *);
				*n_pointer = result;
				str++;
			}
		}
		else
			result += write(1, str++, 1);
	}
	return (result);
}

int		parsing_print(const char **str, va_list ap, t_info *info)
{
	parsing_flag(str, info);
	parsing_wid(str, ap, info);
	if (**str == '.')
		parsing_pre(str, ap, info);
	parsing_format(str, info);
	parsing_varialbe(ap, info);
	clean_up(info);
	return (print_conversions(info));
}

void	clean_up(t_info *info)
{
	if (info->flag == '0' && info->precision >= 0)
		info->flag = 0;
	else if (info->flag == '#' && info->format != 'x' &&
			info->format != 'X' && info->format != 'p')
		info->flag = 0;
	else if (info->flag == '+' && (info->format != 'd' && info->format != 'i'))
		info->flag = 0;
	else if (info->flag == ' ' && info->minus == '-')
		info->flag = 0;
	else if (info->precision >= 0 && info->format == 's')
	{
		if (info->precision < (int)ft_strlen(info->variable))
			info->variable[info->precision] = 0;
		info->precision = -1;
	}
}

void	initialization_info(t_info *info)
{
	info->flag = 0;
	info->format = 0;
	info->precision = -1;
	info->width = 0;
	info->minus = 0;
	info->bonus_flasg = 0;
	info->bonus_format = 0;
}
