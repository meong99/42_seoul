/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 10:01:42 by mchae             #+#    #+#             */
/*   Updated: 2020/10/14 16:56:19 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *target_str, const char *search_str, size_t len)
{
	size_t	i;
	size_t	search_str_len;
	char	*temp_target;

	temp_target = (char*)target_str;
	if (*search_str == '\0')
		return (temp_target);
	i = 0;
	search_str_len = ft_strlen(search_str);
	while (*temp_target && search_str_len + i <= len)
	{
		if (!ft_strncmp(temp_target + i, search_str, search_str_len))
			return (temp_target + i);
		i++;
	}
	return (NULL);
}
