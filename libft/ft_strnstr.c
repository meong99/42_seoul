/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 10:01:42 by mchae             #+#    #+#             */
/*   Updated: 2020/10/23 15:52:41 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *target_str, const char *search_str, size_t len)
{
	size_t	i;
	size_t	search_str_len;

	if (*search_str == '\0')
		return ((char*)target_str);
	i = 0;
	search_str_len = ft_strlen(search_str);
	while (*(char*)target_str && search_str_len + i <= len)
	{
		if (!ft_strncmp((char*)target_str + i, search_str, search_str_len))
			return ((char*)target_str + i);
		i++;
	}
	return (NULL);
}
