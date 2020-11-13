/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_page.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:01:54 by mchae             #+#    #+#             */
/*   Updated: 2020/11/13 19:32:17 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parsing_flag(const char **str, t_info *node)
{
	if (**str == '-')
	{
		node->sign = '-';
		*str = *str + 1;
	}
	if (**str == '#' || **str == ' ' || **str == '+'
		|| (**str == '0' && (*(*str + 1) >= '0' && (*(*str + 1) <= '9'))))
	{
		node->flags = *(*str)++;
	}
	if (**str == '-')
	{
		node->sign = '-';
		*str = *str + 1;
	}
}

void	parsing_wid_or_pre(const char **str, int *wid_or_precision, va_list ap)
{
	if ((**str >= '0' && **str <= '9'))
		while (**str >= '0' && **str <= '9')
		{
			*wid_or_precision *= 10;
			*wid_or_precision += *(*str)++ - '0';
		}
	else if (**str == '*')
		*wid_or_precision = va_arg(ap, int);
}

void	parsing_format(const char **str, t_info *node)
{
	node->format = *(*str)++;
	if ((node->format != 'x' && node->format != 'X') && node->flags == '#')
		node->flags = 0;
	else if ((node->format != 'd' && node->format != 'i') && node->flags == '+')
		node->flags = 0;
}

void	parsing_varialbe(va_list ap, t_info *node)
{
	if (node->format == 'd' || node->format == 'i'
		|| node->format == 'u' || node->format == 'x' || node->format == 'X')
	{
		parsing_varialbe_integer(va_arg(ap, int), node);
	}
	else if (node->format == 'c')
	{
		parsing_varialbe_char(va_arg(ap, int), node);
	}
	else if (node->format == 's')
	{
		parsing_varialbe_str(va_arg(ap, char*), node);
	}
	else if (node->format == 'p')
	{
		parsing_varialbe_pointer((size_t)va_arg(ap, void*), node);
	}
}

void	parsing(const char **str, va_list ap, t_info **head)
{
	t_info	*node;

	(*str)++;
	node = find_end_list(head);
	parsing_flag(str, node);
	parsing_wid_or_pre(str, &node->width, ap);
	if (**str == '.')
	{
		(*str)++;
		parsing_wid_or_pre(str, &node->precision, ap);
	}
	parsing_format(str, node);
	parsing_varialbe(ap, node);
}
