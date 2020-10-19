/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:13:11 by mchae             #+#    #+#             */
/*   Updated: 2020/10/18 20:14:55 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n, int len)
{
	if (n < 0 && len == 0)
		len++;
	if (len == 0 && n == 0)
		return (++len);
	return ((!n) ? len : get_len(n / 10, ++len));
}

static char	*conversion(char *new_str, int n, int len, int sign)
{
	if (len && n / 10 != 0)
		new_str = conversion(new_str, n / 10, --len, sign);
	*new_str = (char)(n % 10 * sign) + '0';
	return (++new_str);
}

char		*ft_itoa(int n)
{
	char	*new_str;
	int		len;

	len = get_len(n, 0);
	if (!(new_str = malloc(len + 1)))
		return (0);
	(n < 0) ? *new_str = '-' : 0;
	(n < 0) ? conversion(new_str + 1, n, len, -1) :
				conversion(new_str, n, len, 1);
	new_str[len] = 0;
	return (new_str);
}