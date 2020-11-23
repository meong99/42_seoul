/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_page.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 21:07:50 by mchae             #+#    #+#             */
/*   Updated: 2020/11/22 22:47:01 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_conversions(t_info *info)
{
	int put_num;
	int i;

	i = 0;
	put_num = 0;
	if (info->flag == '-')
		put_num = printf_left(info);
	else
		put_num = print_right(info);
	free(info->variable);
	return (put_num);
}

int		put_flag(t_info *info)
{
	if (info->bonus_flasg == '#')
	{
		if (info->format == 'X')
			return (write(1, "0X", 2));
		else
			return (write(1, "0x", 2));
	}
	if (info->minus)
		return (write(1, &info->minus, 1));
	if (info->bonus_flasg)
		return (write(1, &info->bonus_flasg, 1));
	return (0);
}

int		printf_left(t_info *info)
{
	int put_num;

	put_num = 0;
	if (info->bonus_flasg || info->minus)
		put_num += put_flag(info);
	info->precision -= ft_strlen(info->variable);
	while (info->precision-- > 0)
		put_num += write(1, "0", 1);
	put_num += write(1, info->variable, ft_strlen(info->variable));
	if (info->format == 'c' && *info->variable == 0)
		put_num += write(1, info->variable, 1);
	while (put_num < info->width)
	{
		if (info->flag == '0')
			put_num += write(1, "0", 1);
		else
			put_num += write(1, " ", 1);
	}
	return (put_num);
}

int		print_right(t_info *info)
{
	int put_num;

	put_num = 0;
	get_width(info);
	if (info->flag == '0' && (info->bonus_flasg || info->minus))
		put_num += put_flag(info);
	while (info->width-- > 0)
	{
		if (info->flag == '0')
			put_num += write(1, "0", 1);
		else
			put_num += write(1, " ", 1);
	}
	if (!(info->flag == '0') && (info->bonus_flasg || info->minus))
		put_num += put_flag(info);
	while (info->precision-- > 0)
		put_num += write(1, "0", 1);
	put_num += write(1, info->variable, ft_strlen(info->variable));
	if (info->format == 'c' && *info->variable == 0)
		put_num += write(1, info->variable, 1);
	return (put_num);
}

void	get_width(t_info *info)
{
	int variable_len;
	int temp;

	temp = 0;
	variable_len = ft_strlen(info->variable);
	info->precision -= variable_len;
	if (info->precision > 0)
		temp += info->precision;
	if (info->bonus_flasg == '#')
		temp += 2;
	else if (info->bonus_flasg || info->minus)
		temp++;
	temp += variable_len;
	if (info->format == 'c' && *info->variable == 0)
		temp++;
	info->width -= temp;
}
