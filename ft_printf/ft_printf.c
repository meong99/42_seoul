/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 11:29:42 by mchae             #+#    #+#             */
/*   Updated: 2020/11/13 21:09:54 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	t_info	*head;
	va_list	ap;

	head = 0;
	va_start(ap, str);
	get_format_specifier(str, ap, &head);
	va_end(ap);
	return (lets_print(head, str));
}

void	get_format_specifier(const char *str, va_list ap, t_info **head)
{
	while (*str)
	{
		if (*str == '%')
			parsing(&str, ap, head);
		else
			str++;
	}
}

int		lets_print(t_info *head, const char *str)
{
	int result_num;

	result_num = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (head->format == 'd' || head->format == 'i')
				result_num += put_integer(head);
			while (*(str - 1) != head->format)
				str++;
			free_node(&head);
		}
		result_num += ft_putchar_fd(*str++, 1);
	}
	return (result_num);
}
