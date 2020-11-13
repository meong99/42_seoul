/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:07:10 by mchae             #+#    #+#             */
/*   Updated: 2020/11/13 15:56:08 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parsing_varialbe_float(double number, t_info *node)
{
	node->variable = (double*)malloc(sizeof(double));
	*(double*)node->variable = number;
	// else if (node->format == 'f')
	// 	{
	// 		parsing_varialbe_float((double)va_arg(ap, double), node);
	// 	}
}

