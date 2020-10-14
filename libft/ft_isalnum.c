/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 12:33:04 by mchae             #+#    #+#             */
/*   Updated: 2020/10/14 16:40:52 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int input_char)
{
	if ((input_char >= '0' && input_char <= '9') ||
		(input_char >= 'a' && input_char <= 'z') ||
		(input_char >= 'A' && input_char <= 'Z'))
		return (1);
	return (0);
}
