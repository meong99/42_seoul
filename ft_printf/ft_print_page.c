/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_page.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:31:18 by mchae             #+#    #+#             */
/*   Updated: 2020/11/13 21:08:05 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_integer(t_info *node)
{
	int put_num;

	put_num = 0;
	if (node->sign == '-')
		put_num = left_sort(node);
	else if (node->sign != '-')
		put_num = right_sort(node);
	return (put_num);
}

int	left_sort(t_info *node)
{
	int put_num;
	int variable_len;

	put_num = 0;
	if (node->flags > 0)
		put_num += ft_putchar_fd(node->flags, 1);
	variable_len = ft_strlen(node->variable);
	node->precision -= variable_len;
	while (node->precision-- > 0)
		put_num += ft_putchar_fd('0', 1);
	put_num += ft_putstr_fd(node->variable, 1);
	while (put_num < node->width)
		put_num += ft_putchar_fd(' ', 1);
	return (put_num);
}

int	right_sort(t_info *node)
{
	int put_num;
	int variable_len;
	int temp;

	temp = 0;
	put_num = 0;
	variable_len = ft_strlen(node->variable);
	node->precision -= variable_len;
	while (node->precision - temp > 0)
		temp++;
	if (node->flags > 0)
		temp++;
	temp += variable_len;
	while (temp < node->width)
		put_num += ft_putchar_fd(' ', 1);
	if (node->flags > 0)
		ft_putchar_fd(node->flags, 1);
	while (node->precision-- > 0)
		put_num += ft_putchar_fd('0', 1);
	put_num += ft_putstr_fd(node->variable, 1);
	return (put_num);
}
