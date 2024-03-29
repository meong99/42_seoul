/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:25:23 by mchae             #+#    #+#             */
/*   Updated: 2021/06/11 16:09:23 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_arr_size(const char *s, char c)
{
	size_t num;

	num = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s && *s != c)
			{
				s++;
			}
			num++;
		}
		else
			s++;
	}
	return (num);
}

static size_t	get_alloc_size(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void		*free_arr(char **double_str, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(double_str[index]);
		double_str[i++] = NULL;
	}
	free(double_str);
	double_str = NULL;
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**double_str;
	size_t	arr_size;
	size_t	alloc_size;
	size_t	index;

	if (!s)
		return (NULL);
	index = 0;
	arr_size = get_arr_size(s, c);
	if (!(double_str = (char**)malloc(sizeof(char*) * (arr_size + 1))))
		return (NULL);
	while (arr_size--)
	{
		while (*s && *s == c)
			s++;
		alloc_size = get_alloc_size(s, c) + 1;
		if (!(double_str[index] = (char*)malloc(alloc_size)))
			return (free_arr(double_str, index));
		ft_strlcpy(double_str[index++], s, alloc_size);
		s = ft_strchr(s, c);
	}
	double_str[index] = NULL;
	return (double_str);
}
