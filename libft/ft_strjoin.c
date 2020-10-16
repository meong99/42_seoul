/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 00:04:37 by mchae             #+#    #+#             */
/*   Updated: 2020/10/15 01:31:27 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	join_str_len;

	if (!s1 || !s2)
		return (0);
	join_str_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(new_str = (char*)malloc(join_str_len)))
		return (0);
	new_str[0] = 0;
	ft_strlcat(new_str, s1, join_str_len);
	ft_strlcat(new_str, s2, join_str_len);
	return (new_str);
}
