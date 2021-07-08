/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:13:11 by mchae             #+#    #+#             */
/*   Updated: 2021/07/08 18:22:52 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n, int len)
{
	if (n == 0)
		return (++len);
	else if (n < 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*conversion(char *new_str, int n, int sign)
{
	if (n / 10)
		new_str = conversion(new_str, n / 10, sign);
	*new_str = (char)(n % 10 * sign) + '0';
	return (++new_str);
}

char	*ft_itoa(int n)
{
	char	*new_str;
	int		len;

	len = get_len(n, 0);
	new_str = malloc(len + 1);
	if (!new_str)
		return (0);
	if (n < 0)
	{
		*new_str = '-';
		conversion(new_str + 1, n, -1);
	}
	else
		conversion(new_str, n, 1);
	new_str[len] = 0;
	return (new_str);
}
