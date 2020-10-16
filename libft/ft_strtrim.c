/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 01:07:26 by mchae             #+#    #+#             */
/*   Updated: 2020/10/16 22:26:29 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		part_start(char **s1, char *set, size_t set_len)
{
	while (set_len--)
	{
		if (ft_strchr(set, **s1))
			*s1 += 1;
		else
			return ;
	}
}

static size_t	part_end(char *s1, const char *set,
						size_t set_len, size_t cpy_size)
{
	while (set_len--)
	{
		if (ft_strrchr(set, s1[cpy_size - 1]))
			cpy_size--;
		else
			break ;
	}
	return (cpy_size);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	char	*temp_s1;
	size_t	set_len;
	size_t	cpy_len;

	if (!s1 && !set)
		return (ft_strdup(""));
	set_len = ft_strlen(set);
	temp_s1 = (char*)s1;
	part_start(&temp_s1, (char*)set, set_len);
	cpy_len = part_end(temp_s1, set, set_len, ft_strlen(temp_s1));
	if (!(new_str = malloc(cpy_len + 1)))
		return (NULL);
	ft_strlcpy(new_str, temp_s1, cpy_len + 1);
	return (new_str);
}
