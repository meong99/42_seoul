/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 10:33:37 by mchae             #+#    #+#             */
/*   Updated: 2020/10/22 21:04:12 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp_s;

	temp_s = (char*)s + ft_strlen(s);
	while (temp_s >= s)
	{
		if (*temp_s == c)
			return (temp_s);
		temp_s--;
	}
	return (NULL);
}
