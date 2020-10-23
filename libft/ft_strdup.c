/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:10:24 by mchae             #+#    #+#             */
/*   Updated: 2020/10/23 14:58:30 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*result;

	i = 0;
	if (!(result = (char *)malloc(ft_strlen(s) + 1)))
		return (0);
	while (s[i] != 0)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = 0;
	return (result);
}
