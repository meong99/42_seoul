/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 18:51:01 by mchae             #+#    #+#             */
/*   Updated: 2020/11/22 22:47:30 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parsing_h_hh(int number, t_info *info)
{
	int my_switch;

	my_switch = get_bonus_switch(number, info);
	if (my_switch == 1)
		info->variable = ft_itoa_base((size_t)((short)number * -1),
						info->format, 10);
	else if (my_switch == 2)
		info->variable = ft_itoa_base((size_t)(unsigned short)number,
						info->format, 10);
	else if (my_switch == 3)
		info->variable = ft_itoa_base((size_t)(unsigned short)number,
						info->format, 16);
	else if (my_switch == 4)
		info->variable = ft_itoa_base((size_t)((char)number * -1),
						info->format, 10);
	else if (my_switch == 5)
		info->variable = ft_itoa_base((size_t)(unsigned char)number,
						info->format, 10);
	else if (my_switch == 6)
		info->variable = ft_itoa_base((size_t)(unsigned char)number,
						info->format, 16);
	if (number == 0 && !info->precision)
		*info->variable = 0;
	if (number == 0 && info->bonus_flasg == '#')
		info->bonus_flasg = 0;
}

void	parsing_l_ll(long long number, t_info *info)
{
	int my_switch;

	my_switch = get_bonus_switch(number, info);
	if (my_switch == 1)
		info->variable = ft_itoa_base((size_t)((long)number * -1),
						info->format, 10);
	else if (my_switch == 2)
		info->variable = ft_itoa_base((size_t)(unsigned long)number,
						info->format, 10);
	else if (my_switch == 3)
		info->variable = ft_itoa_base((size_t)(unsigned long)number,
						info->format, 16);
	else if (my_switch == 4)
		info->variable = ft_itoa_base((size_t)number * -1,
						info->format, 10);
	else if (my_switch == 5)
		info->variable = ft_itoa_base((size_t)number,
						info->format, 10);
	else if (my_switch == 6)
		info->variable = ft_itoa_base((size_t)number,
						info->format, 16);
	if (number == 0 && !info->precision)
		*info->variable = 0;
	if (number == 0 && info->bonus_flasg == '#')
		info->bonus_flasg = 0;
}

int		get_bonus_switch(long long number, t_info *info)
{
	int my_switch;

	if (number < 0 && (info->format == 'd' || info->format == 'i'))
	{
		my_switch = 1;
		info->minus = '-';
	}
	else if (info->format == 'd' || info->format == 'i' || info->format == 'u')
		my_switch = 2;
	else
		my_switch = 3;
	if (info->bonus_format == 'H' || info->bonus_format == 'L')
		my_switch += 3;
	return (my_switch);
}
