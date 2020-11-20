/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 18:51:01 by mchae             #+#    #+#             */
/*   Updated: 2020/11/20 22:49:54 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parsing_bonus(int number, t_info *info)
{
	if (info->bonus_format == 'h')
	{
		if (number < 0 && (info->format == 'd' || info->format == 'i'))
			info->variable = ft_itoa_base((size_t)((unsigned short)number * -1),
							info->format, 10);
		else
			info->variable = ft_itoa_base((size_t)(unsigned short)number,
							info->format, 10);
	}
	else
	{
		if (number < 0 && (info->format == 'd' || info->format == 'i'))
			info->variable = ft_itoa_base((size_t)((unsigned char)number * -1),
							info->format, 10);
		else
			info->variable = ft_itoa_base((size_t)(unsigned char)number,
							info->format, 10);
	}
}
