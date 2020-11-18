/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_page.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:01:54 by mchae             #+#    #+#             */
/*   Updated: 2020/11/18 17:30:01 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parsing_flag(const char **str, t_info *info)
{
	while (**str == '-' || **str == '#' || **str == ' ' || **str == '+'
		|| (**str == '0' && ((*(*str + 1) >= '0' &&
		(*(*str + 1) <= '9')) || (*(*str + 1) == '*') || (*(*str + 1) == '-'))))
	{
		if (**str == '-')
			info->sign = '-';
		else if (**str == '#' || **str == ' ' || **str == '+')
			info->bonus_flasgs = **str;
		else
			info->flags = **str;
		*str = *str + 1;
	}
}

void	parsing_wid(const char **str, va_list ap, t_info *info)
{
	if ((**str >= '0' && **str <= '9'))
	{
		while (**str >= '0' && **str <= '9')
		{
			info->width *= 10;
			info->width += *(*str)++ - '0';
		}
	}
	else if (**str == '*')
	{
		info->width = va_arg(ap, int);
		if (info->width < 0)
		{
			info->width *= -1;
			info->sign = '-';
		}
		(*str)++;
	}
}

void	parsing_pre(const char **str, va_list ap, t_info *info)
{
	if ((**str >= '0' && **str <= '9'))
	{
		while (**str >= '0' && **str <= '9')
		{
			info->precision *= 10;
			info->precision += *(*str)++ - '0';
		}
	}
	else if (**str == '*')
	{
		info->precision = va_arg(ap, int);
		(*str)++;
	}
}

void	parsing_varialbe(va_list ap, t_info *info)
{
	if (info->format == 'd' || info->format == 'i'
		|| info->format == 'u' || info->format == 'x' || info->format == 'X')
	{
		parsing_varialbe_integer(va_arg(ap, int), info);
	}
	else if (info->format == 'c')
	{
		parsing_varialbe_char(va_arg(ap, int), info);
	}
	else if (info->format == 's')
	{
		parsing_varialbe_str(va_arg(ap, char*), info);
	}
	else if (info->format == 'p')
	{
		parsing_varialbe_pointer(va_arg(ap, size_t), info);
	}
	else
	{
		parsing_varialbe_char('%', info);
		info->bonus_flasgs = 0;
	}
}
