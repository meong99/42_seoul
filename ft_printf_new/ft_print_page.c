/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_page.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 21:07:50 by mchae             #+#    #+#             */
/*   Updated: 2020/11/15 21:45:38 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	lets_print(t_info *node)
{
	int put_num;
	int i;

	i = 0;
	put_num = 0;
	if (node->precision == 0 && node->variable[0] == '0')
	{
		while (i++ < node->width)
			put_num += ft_putchar_fd(' ', 1);
		return (put_num);
	}
	if (node->sign == '-')
		put_num = left_sort(node);
	else
		put_num = right_sort(node);
	return (put_num);
}

int	put_flag(t_info *node)
{
	if (node->flags == '#')
	{
		if (node->format == 'X')
			return (ft_putstr_fd("0X", 1));
		else
			return (ft_putstr_fd("0x", 1));
	}
	else if (node->flags != '0')
		return (ft_putchar_fd(node->flags, 1));
	else if (node->minus == '-')
		return (ft_putchar_fd(node->minus, 1));
	return (0);
}

int	left_sort(t_info *node)
{
	int put_num;
	int variable_len;

	put_num = 0;
	if (node->flags > 0)
		put_num += put_flag(node);
	variable_len = ft_strlen(node->variable);
	node->precision -= variable_len;
	while (node->precision-- > 0)
		put_num += ft_putchar_fd('0', 1);
	put_num += ft_putstr_fd(node->variable, 1);
	while (put_num < node->width)
	{
		if (node->flags == '0')
			put_num += ft_putchar_fd('0', 1);
		else
			put_num += ft_putchar_fd(' ', 1);
	}
	return (put_num);
}

int	right_sort(t_info *node)
{
	int put_num;

	put_num = 0;
	get_print_width(node);
	put_num += ft_putchar_fd(node->minus, 1);
	node->minus = -1;
	while (node->width-- > 0)
	{
		if (node->flags == '0')
			put_num += ft_putchar_fd('0', 1);
		else
			put_num += ft_putchar_fd(' ', 1);
	}
	if (node->flags > 0)
		put_num += put_flag(node);
	while (node->precision-- > 0)
		put_num += ft_putchar_fd('0', 1);
	put_num += ft_putstr_fd(node->variable, 1);
	return (put_num);
}

void	get_print_width(t_info *node)
{
	int variable_len;
	int temp;

	temp = 0;
	variable_len = ft_strlen(node->variable);
	node->precision -= variable_len;
	while (node->precision - temp > 0)
		temp++;
	if (node->flags > 0)
		temp++;
	temp += variable_len;
	node->width -= temp;
}
