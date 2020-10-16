/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:25:45 by mchae             #+#    #+#             */
/*   Updated: 2020/10/14 23:50:17 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s || ft_strlen(s) <= start || !len)
		return (ft_strdup(""));
	if (!(str = malloc(++len)))
		return (0);
	ft_strlcpy(str, s + start, len);
	return (str);
}
