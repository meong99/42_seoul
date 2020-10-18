/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:25:23 by mchae             #+#    #+#             */
/*   Updated: 2020/10/18 22:42:10 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t		separation_num(const char *s, char c)
{
	size_t i;

	i = 0;
	while (*s)
	{
		if (*s == c)
		{
			while (*s && *s == c)
			{
				s++;
			}
			i++;
		}
		else
			s++;
	}
	return (i) ? i : i++;
}

static size_t	alloc_size(char const *s, char c)
{
	size_t i;

	i = 0;
	while (*s == c)
		s++;
	while (s[i])
	{
		if (s[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (i);
}

char				**ft_split(char const *s, char c)
{
	char	**double_str;
	size_t	arr_size;
	size_t	asd;
	size_t	index;

	if (!s)
		return (0);
	index = 0;
	arr_size = separation_num(s, c);
	if (!(double_str = (char**)malloc(sizeof(char*) * arr_size)))
		return (NULL);
	while (*s)
	{
		asd = alloc_size(s, c) + 1;
		if (!(double_str[index] = (char*)malloc(asd)))
			return (NULL);
		ft_strlcpy(double_str[index], s, asd);
		s += asd;
	}
	double_str[index] = 0;
	return (double_str);
}
