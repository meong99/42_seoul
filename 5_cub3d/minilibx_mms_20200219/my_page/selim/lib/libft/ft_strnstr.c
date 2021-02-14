/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selim <selim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:07:28 by selim             #+#    #+#             */
/*   Updated: 2020/10/05 17:07:46 by selim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t l_len;

	if (*little == '\0')
		return (char *)big;
	l_len = ft_strlen(little);
	while (*big != '\0' && len-- >= l_len)
	{
		if (*big == *little && ft_strncmp(big, little, l_len) == 0)
			return ((char *)big);
		big++;
	}
	return (0);
}
