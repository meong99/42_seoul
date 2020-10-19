/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:25:23 by mchae             #+#    #+#             */
/*   Updated: 2020/10/19 21:42:59 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		passing_delimiter(const char **s, char c)
{
	while (**s == c && **s)
		*s += 1;
}

static size_t	separation_num(const char *s, char c)
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
			passing_delimiter(&s, c);
	}
	return (num);
}

static size_t	get_alloc_size(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] != c)
		i++;
	return (i);
}

static void		*free_arr(char **double_str, size_t arr_size, size_t index)
{
	while (arr_size-- >= 0)
	{
		while (index >= 0)
		{
			free(double_str[index]);
			double_str[index--] = 0;
		}
	}
	free(double_str);
	double_str = 0;
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**double_str;
	size_t	arr_size;
	size_t	alloc_size;
	size_t	index;

	if (!s)
		return (0);
	index = 0;
	arr_size = separation_num(s, c);
	if (!(double_str = (char**)malloc(sizeof(char*) * arr_size)))
		return (NULL);
	while (arr_size--)
	{
		passing_delimiter(&s, c);
		alloc_size = get_alloc_size(s, c);
		if (!(double_str[index] = (char*)malloc(alloc_size + 1)))
			return (free_arr(double_str, arr_size, index));
		ft_strlcpy(double_str[index++], s, alloc_size + 1);
		s += alloc_size;
	}
	double_str[index] = 0;
	return (double_str);
}
