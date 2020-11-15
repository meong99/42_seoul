/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_ctrl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:06:47 by mchae             #+#    #+#             */
/*   Updated: 2020/11/15 21:33:49 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_info	*new_list(void)
{
	t_info *node;

	node = (t_info*)malloc(sizeof(t_info));
	node->flags = -1;
	node->format = -1;
	node->precision = -1;
	node->sign = -1;
	node->width = -1;
	node->variable = 0;
	node->minus = -1;
	return (node);
}
