/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:52:16 by mchae             #+#    #+#             */
/*   Updated: 2021/10/20 18:50:43 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_arr_size(const char *str, char c, \
	int option, int (*f)(char *, char *, int))
{
	size_t	num;
	size_t	i;
	char	*s;

	i = 0;
	num = 0;
	s = (char *)str;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && (s[i] != c || f(s, &s[i], option) == 1))
				i++;
			num++;
		}
		else
			i++;
	}
	return (num);
}

static size_t	get_alloc_size(char const *str, char c, \
	int option, int (*f)(char *, char *, int))
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)str;
	while (s[i] && (s[i] != c || f(s, &s[i], option)))
		i++;
	return (i);
}

static void	*free_arr(char **double_str, size_t index)
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

static void	*copy_str(t_split *split, char *str, \
	char c, int (*f)(char *, char *, int))
{
	char	*tmp;

	tmp = str;
	while (split->arr_size--)
	{
		while (*tmp && *tmp == c)
			tmp++;
		split->alloc_size = get_alloc_size(tmp, c, split->option, f) + 1;
		split->double_str[split->index] = (char *)malloc(split->alloc_size);
		if (!split->double_str[split->index])
			return (free_arr(split->double_str, split->index));
		ft_strlcpy(split->double_str[split->index++], tmp, split->alloc_size);
		while (1)
		{
			tmp = ft_strchr(tmp, c);
			if (tmp && f(str, tmp, split->option))
				tmp++;
			else
				break ;
		}
	}
	return (str);
}

char	**ft_split_f(char const *s, char c, \
	int option, int (*f)(char *, char *, int))
{
	t_split	split;

	if (!s)
		return (NULL);
	split.index = 0;
	split.option = option;
	split.arr_size = get_arr_size(s, c, option, f);
	split.double_str = (char **)malloc(sizeof(char *) * (split.arr_size + 1));
	if (!split.double_str)
		return (NULL);
	if (copy_str(&split, (char *)s, c, f) == NULL)
		return (NULL);
	split.double_str[split.index] = NULL;
	return (split.double_str);
}
