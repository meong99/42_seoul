/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selim <selim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 13:53:52 by selim             #+#    #+#             */
/*   Updated: 2020/10/15 20:37:09 by selim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		while (s[i] && (s[i] == c))
			i++;
		if (s[i] && (s[i] != c))
		{
			cnt++;
			while (s[i] && (s[i] != c))
				i++;
		}
	}
	return (cnt);
}

char	*malloc_word(char const *s, char c)
{
	size_t	i;
	char	*word;

	i = 0;
	while (s[i] && (s[i] != c))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (word == 0)
		return (0);
	i = 0;
	while (s[i] && (s[i] != c))
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**free_buff(char **arr, size_t cnt)
{
	while (cnt-- > 0)
	{
		free(arr[cnt]);
		arr[cnt] = 0;
	}
	free(arr);
	arr = 0;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		wordcnt;
	char		**arr;

	if (!s)
		return (0);
	if ((arr = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1))) == 0)
		return (0);
	i = 0;
	wordcnt = 0;
	while (s[i] != '\0')
	{
		while (s[i] && (s[i] == c))
			i++;
		if (s[i] && (s[i] != c))
		{
			if (!(arr[wordcnt] = malloc_word(&s[i], c)))
				return (free_buff(arr, wordcnt));
			wordcnt++;
			while (s[i] && (s[i] != c))
				i++;
		}
	}
	arr[wordcnt] = 0;
	return (arr);
}
