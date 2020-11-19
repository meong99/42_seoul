/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_page.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:01:54 by mchae             #+#    #+#             */
/*   Updated: 2020/11/19 21:48:50 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parsing_flag(const char **str, t_info *info)
{
	while (**str == '-' || ft_strchr(BONUS_FLAGS, **str)
		|| (**str == '0' && !((*(*str + 1) == '.') || ft_isalpha(*(*str + 1)))))
	{
		if (ft_strchr(BONUS_FLAGS, **str))
			info->bonus_flasg = **str;
		else if (info->flag != '-')
			info->flag = **str;
		*str = *str + 1;
	}
}

void	parsing_wid(const char **str, va_list ap, t_info *info)
{
	if (ft_isdigit(**str))
	{
		while (ft_isdigit(**str))
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
			info->flag = '-';
		}
		(*str)++;
	}
}

void	parsing_pre(const char **str, va_list ap, t_info *info)
{
	if (ft_isdigit(**str))
	{
		while (ft_isdigit(**str))
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

void	parsing_format(const char **str, t_info *info)
{
	int i;
	int check_bonus_format;

	i = 3;
	check_bonus_format = 0;
	if (**str == 'l' || **str == 'h')
		while (**str == 'l' || **str == 'h')
		{
			info->bonus_format = *(*str)++;
			check_bonus_format++;
		}
	info->format = **str;
	if (check_bonus_format > 1)
		info->bonus_format = ft_toupper(info->bonus_format);
	if (**str)
		*str = (*str) + 1;
	if (info->format != 'X')
		info->format = ft_tolower(info->format);
}

void	parsing_varialbe(va_list ap, t_info *info)
{
	if (ft_strchr(FORMAT_D_I_U_X_XX, info->format))
	{
		parsing_varialbe_integer(va_arg(ap, long), info);
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
		parsing_varialbe_pointer(va_arg(ap, long long), info);
	else
	{
		parsing_varialbe_char('%', info);
		info->bonus_flasg = 0;
	}
}
