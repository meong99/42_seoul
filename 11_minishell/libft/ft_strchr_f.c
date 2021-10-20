/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:52:20 by mchae             #+#    #+#             */
/*   Updated: 2021/10/20 17:40:41 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_f(const char *s, int c, \
	int op, int (*f)(char *, char *, int))
{
	int		i;
	char	*str;

	i = -1;
	if (s == NULL)
		return (NULL);
	str = (char *)s;
	while (*str)
	{
		if (*str == c && f((char *)s, str, op) == 0)
			return (str);
		str++;
	}
	if (c == '\0')
		return (str);
	return (NULL);
}
