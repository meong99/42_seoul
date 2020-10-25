/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 10:01:42 by mchae             #+#    #+#             */
/*   Updated: 2020/10/25 15:43:57 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *heystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	if (*needle == '\0')
		return ((char*)heystack);
	i = 0;
	needle_len = ft_strlen(needle);
	while (*(char*)heystack && needle_len + i <= len)
	{
		if (!ft_strncmp((char*)heystack + i, needle, needle_len))
			return ((char*)heystack + i);
		i++;
	}
	return (NULL);
}
