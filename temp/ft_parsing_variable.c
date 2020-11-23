/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_variable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:26:13 by mchae             #+#    #+#             */
/*   Updated: 2020/11/22 23:04:56 by mchae            ###   ########.fr       */
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

void	parsing_varialbe_number(int number, t_info *info)
{
	int my_switch;

	my_switch = get_switch(number, info);
	if (my_switch == 1)
		info->variable = ft_itoa_base((size_t)number * -1,
						info->format, 10);
	else if (my_switch == 2)
		info->variable = ft_itoa_base((size_t)(unsigned int)number,
						info->format, 10);
	else if (my_switch == 3)
		info->variable = ft_itoa_base((size_t)(unsigned int)number,
						info->format, 16);
	if (number == 0 && !info->precision)
		*info->variable = 0;
	if (number == 0 && info->bonus_flasg == '#')
		info->bonus_flasg = 0;
}

int		get_switch(int number, t_info *info)
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
	return (my_switch);
}

void	parsing_varialbe_char(char c, t_info *info)
{
	info->variable = (char*)malloc(2);
	ft_strlcpy(info->variable, &c, 2);
	info->precision = -1;
}

void	parsing_varialbe_pointer(size_t pointer, t_info *info)
{
	info->bonus_flasg = '#';
	info->variable = ft_itoa_base(pointer, info->format, 16);
	if (!pointer && info->precision >= 0)
		*info->variable = 0;
}
