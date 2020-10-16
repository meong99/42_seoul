/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 01:07:26 by mchae             #+#    #+#             */
/*   Updated: 2020/10/16 23:25:30 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		part_start(char **s1, char *set)
{
	while (**s1)
	{
		if (ft_strchr(set, **s1))
			*s1 += 1;
		else
			return ;
	}
}

static size_t	part_end(char *s1, const char *set,
						size_t cpy_size)
{
	while (s1[cpy_size])
	{
		if (ft_strrchr(set, s1[cpy_size]))
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

	if (!*s1 && !*set)
		return (ft_strdup(""));
	set_len = ft_strlen(set);
	temp_s1 = (char*)s1;
	part_start(&temp_s1, (char*)set);
	cpy_len = part_end(temp_s1, set, ft_strlen(temp_s1));
	if (!(new_str = ft_calloc(cpy_len, cpy_len)))
		return (NULL);
	ft_strlcat(new_str, temp_s1, cpy_len);
	return (new_str);
}
