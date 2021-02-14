/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selim <selim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:52:14 by selim             #+#    #+#             */
/*   Updated: 2020/10/05 15:52:15 by selim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *ret;

	ret = 0;
	while (1)
	{
		if (*str == (unsigned char)c)
			ret = (char *)str;
		if (*str == 0)
			break ;
		++str;
	}
	return (ret);
}
