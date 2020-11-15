/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 11:29:42 by mchae             #+#    #+#             */
/*   Updated: 2020/11/15 21:35:58 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	t_info	*info;
	va_list	ap;
	int		result;

	info = new_list();
	va_start(ap, str);
	result = get_format_specifier(str, ap, info);
	va_end(ap);
	return (result);
}

int		get_format_specifier(const char *str, va_list ap, t_info *info)
{
	int result;

	result = 0;
	while (*str)
	{
		if (*str == '%')
			result += print(&str, ap, info);
		else
			result += ft_putchar_fd(*str++, 1);
	}
	return (result);
}

int		print(const char **str, va_list ap, t_info *info)
{
	(*str)++;
	if (**str == '%')
	{
		(*str)++;
		return (ft_putchar_fd('%', 1));
	}
	parsing_flag(str, info);
	parsing_wid(str, ap, info);
	if (**str == '.')
	{
		(*str)++;
		info->flags = -1;
		parsing_pre(str, ap, info);
	}
	info->format = *(*str)++;
	parsing_varialbe(ap, info);
	clean_up(info);
	return (lets_print(info));
}

void		clean_up(t_info *info)
{
	if (info->flags == '0' && info->sign == '-')
		info->flags = -1;
	else if (info->flags == '#' && (info->format != 'x' && info->format != 'X'))
		info->flags = -1;
	else if (info->flags == '+' && (info->flags != 'd' && info->flags != 'i'))
		info->flags = -1;
}
