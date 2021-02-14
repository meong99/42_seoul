/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selim <selim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 12:22:50 by selim             #+#    #+#             */
/*   Updated: 2020/10/07 12:22:52 by selim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		isincluded(char a, char const *set)
{
	while (*set)
	{
		if (a == *set++)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	char	*start;
	char	*end;
	size_t	len;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = (char *)s1;
	end = start + ft_strlen(s1);
	while (*start && isincluded(*start, set))
		++start;
	while (start < end && isincluded(*(end - 1), set))
		--end;
	len = end - start + 1;
	ret = malloc(sizeof(char) * len);
	if (ret == 0)
		return (0);
	ft_strlcpy(ret, start, len);
	return (ret);
}
