/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 00:04:37 by mchae             #+#    #+#             */
/*   Updated: 2021/03/26 14:29:04 by mchae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	join_str_len;

	if (!s1 || !s2)
		return (NULL);
	join_str_len = ft_strlen(s1) + ft_strlen(s2) + 1 + 1;
	if (!(new_str = (char*)malloc(join_str_len)))
		return (NULL);
	ft_strlcpy(new_str, s1, join_str_len);
	ft_strlcat(new_str, "\n", join_str_len);
	ft_strlcat(new_str, s2, join_str_len);
	return (new_str);
}
