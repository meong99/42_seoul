/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_page.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 21:07:50 by mchae             #+#    #+#             */
/*   Updated: 2020/11/18 16:55:50 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_conversions(t_info *info)
{
	int put_num;
	int i;

	i = 0;
	put_num = 0;
	if (info->sign == '-')
		put_num = left_sort(info);
	else
		put_num = right_sort(info);
	free(info->variable);
	return (put_num);
}

int		put_flag(t_info *info)
{
	if (info->bonus_flasgs == '#')
	{
		if (info->format == 'X')
			return (ft_putstr_fd("0X", 1));
		else
			return (ft_putstr_fd("0x", 1));
	}
	else if (info->minus)
		return (ft_putchar_fd(info->minus, 1));
	else if (info->bonus_flasgs)
		return (ft_putchar_fd(info->bonus_flasgs, 1));
	return (0);
}

int		left_sort(t_info *info)
{
	int put_num;
	int variable_len;

	put_num = 0;
	if (info->bonus_flasgs || info->minus)
		put_num += put_flag(info);
	variable_len = ft_strlen(info->variable);
	info->precision -= variable_len;
	while (info->precision-- > 0)
		put_num += ft_putchar_fd('0', 1);
	put_num += ft_putstr_fd(info->variable, 1);
	if (info->format == 'c' && *info->variable == 0)
		put_num += ft_putchar_fd(*info->variable, 1);
	while (put_num < info->width)
	{
		if (info->flags == '0')
			put_num += ft_putchar_fd('0', 1);
		else
			put_num += ft_putchar_fd(' ', 1);
	}
	return (put_num);
}

int		right_sort(t_info *info)
{
	int put_num;

	put_num = 0;
	get_width(info);
	if (info->flags == '0' && (info->bonus_flasgs || info->minus))
		put_num += put_flag(info);
	while (info->width-- > 0)
	{
		if (info->flags == '0')
			put_num += ft_putchar_fd('0', 1);
		else
			put_num += ft_putchar_fd(' ', 1);
	}
	if (!(info->flags == '0') &&
		(info->bonus_flasgs || info->minus))
		put_num += put_flag(info);
	while (info->precision-- > 0)
		put_num += ft_putchar_fd('0', 1);
	put_num += ft_putstr_fd(info->variable, 1);
	if (info->format == 'c' && *info->variable == 0)
		put_num += ft_putchar_fd(*info->variable, 1);
	return (put_num);
}

void	get_width(t_info *info)
{
	int variable_len;
	int temp;

	temp = 0;
	variable_len = ft_strlen(info->variable);
	info->precision -= variable_len;
	while (info->precision - temp > 0)
		temp++;
	if (info->bonus_flasgs || info->minus)
		temp++;
	if (info->bonus_flasgs == '#')
		temp++;
	temp += variable_len;
	if (info->format == 'c' && *info->variable == 0)
		temp++;
	info->width -= temp;
}
