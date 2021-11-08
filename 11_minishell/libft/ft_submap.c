/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_submap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:55:22 by mchae             #+#    #+#             */
/*   Updated: 2021/11/08 23:55:24 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ret_len(char *str, char *start, char *end, char *strmap)
{
	int		len;

	len = start - str;
	len += ft_strlen(strmap);
	if (*end == '\0')
		str = end;
	else
		str = end + 1;
	len += ft_strlen(str);
	return (len);
}

char	*ft_submap(char *str, char *start, char *end, char *strmap)
{
	int		len;
	size_t	i;
	char	*new_str;

	len = ret_len(str, start, end, strmap);
	new_str = malloc(len + 1);
	ft_memcpy(new_str, str, start - str);
	i = start - str;
	if (*end == '\0')
		str = end;
	else
		str = end + 1;
	ft_memcpy(new_str + i, strmap, ft_strlen(strmap));
	i += ft_strlen(strmap);
	ft_memcpy(new_str + i, str, ft_strlen(str));
	new_str[len] = 0;
	return (new_str);
}
