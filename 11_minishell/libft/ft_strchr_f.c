/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:52:20 by mchae             #+#    #+#             */
/*   Updated: 2021/09/16 17:02:18 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_f(const char *s, int c, int (*f)(char *, char *))
{
	int		i;
	char	*str;

	i = -1;
	str = (char *)s;
	while (*str)
	{
		if (*str == c && f((char *)s, str) == 0)
			return (str);
		str++;
	}
	if (c == '\0')
		return (str);
	return (NULL);
}
