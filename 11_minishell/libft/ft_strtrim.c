/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 01:07:26 by mchae             #+#    #+#             */
/*   Updated: 2021/07/08 18:04:08 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	is_include(char **s1, char *set, int sign)
{
	while (**s1)
	{
		if (ft_strchr(set, **s1))
			*s1 += sign;
		else
			return ;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	char	*start_s1;
	char	*end_s1;
	size_t	cpy_len;

	if (!*set)
		return (ft_strdup(s1));
	if (!s1)
		return (NULL);
	start_s1 = (char *)s1;
	end_s1 = (char *)s1 + ft_strlen(s1) - 1;
	is_include(&start_s1, (char *)set, 1);
	if (!*start_s1)
		return (ft_strdup(""));
	is_include(&end_s1, (char *)set, -1);
	cpy_len = ft_strlen(start_s1) - ft_strlen(end_s1) + 2;
	new_str = malloc(cpy_len);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, start_s1, cpy_len);
	return (new_str);
}
