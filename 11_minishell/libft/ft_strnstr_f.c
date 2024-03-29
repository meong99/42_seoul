/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:55:17 by mchae             #+#    #+#             */
/*   Updated: 2021/11/08 23:55:18 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr_f(const char *heystack, const char *needle, size_t len, \
	int (*f)(char *, char *, int))
{
	size_t	i;
	size_t	needle_len;

	if (*needle == '\0')
		return ((char *)heystack);
	i = 0;
	needle_len = ft_strlen(needle);
	while (*(char *)heystack && needle_len + i <= len)
	{
		if (!ft_strncmp((char *)heystack + i, needle, needle_len) && \
		!f((char *)heystack, (char *)heystack + i, 0))
			return ((char *)heystack + i);
		i++;
	}
	return (NULL);
}
