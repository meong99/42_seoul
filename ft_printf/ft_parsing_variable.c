/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_variable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:26:13 by mchae             #+#    #+#             */
/*   Updated: 2020/11/13 20:36:58 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parsing_varialbe_str(char *str, t_info *node)
{
	node->variable = (char*)malloc(ft_strlen(str) + 1);
	ft_strlcpy((char*)node->variable, str, ft_strlen(str) + 1);
}

void	parsing_varialbe_integer(int number, t_info *node)
{
	node->variable = ft_itoa_base((size_t)(unsigned int)number,
					node->format, 10);
	if (number < 0)
		node->flags = '-';
}

void	parsing_varialbe_char(char c, t_info *node)
{
	node->variable = (char*)malloc(2);
	*node->variable = c;
	node->variable[1] = 0;
}

void	parsing_varialbe_pointer(size_t pointer, t_info *node)
{
	node->variable = ft_itoa_base(pointer, node->format, 16);
}
