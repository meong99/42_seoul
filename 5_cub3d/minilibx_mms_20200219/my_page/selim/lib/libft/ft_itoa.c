/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selim <selim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 17:56:54 by selim             #+#    #+#             */
/*   Updated: 2020/10/07 17:56:56 by selim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		find_len(unsigned int tmp)
{
	int len;

	len = 1;
	while (tmp >= 10)
	{
		tmp = tmp / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*ret;
	int				len;
	unsigned int	tmp;

	len = (n < 0 ? 1 : 0);
	tmp = (n < 0 ? (unsigned int)n * -1 : (unsigned int)n);
	len += find_len(tmp);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	ret[len--] = '\0';
	while (len >= 0)
	{
		ret[len] = (tmp % 10) + '0';
		tmp = tmp / 10;
		len--;
	}
	if (n < 0)
		ret[0] = '-';
	return (ret);
}
