/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_page.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:01:54 by mchae             #+#    #+#             */
/*   Updated: 2020/11/23 14:49:17 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parsing_flag(const char **str, t_info *info)
{
	while (ft_strchr(BONUS_FLAGS, **str) || ft_strchr(FLAGS, **str))
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
		info->width = ft_atoi(*str);
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
	while (ft_isdigit(**str))
		(*str)++;
}

void	parsing_pre(const char **str, va_list ap, t_info *info)
{
	(*str)++;
	info->precision = 0;
	if (info->flag == '0')
		info->flag = 0;
	if (ft_isdigit(**str))
		info->precision = ft_atoi(*str);
	else if (**str == '*')
	{
		info->precision = va_arg(ap, int);
		(*str)++;
	}
	while (ft_isdigit(**str))
		(*str)++;
}

void	parsing_format(const char **str, t_info *info)
{
	int check_bonus_format;

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
		if (info->bonus_format == 'l' || info->bonus_format == 'L')
			parsing_l_ll(va_arg(ap, long long), info);
		else if (info->bonus_format)
			parsing_h_hh(va_arg(ap, int), info);
		else
			parsing_varialbe_number(va_arg(ap, int), info);
	}
	else if (info->format == 'c')
		parsing_varialbe_char(va_arg(ap, int), info);
	else if (info->format == 's')
		parsing_varialbe_str(va_arg(ap, char*), info);
	else if (info->format == 'p')
		parsing_varialbe_pointer(va_arg(ap, size_t), info);
	else if (info->format == '%')
	{
		parsing_varialbe_char('%', info);
		info->bonus_flasg = 0;
	}
}
