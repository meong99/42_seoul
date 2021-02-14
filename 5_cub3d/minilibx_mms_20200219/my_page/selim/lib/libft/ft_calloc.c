/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selim <selim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 11:27:35 by selim             #+#    #+#             */
/*   Updated: 2020/10/07 14:26:29 by selim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	char			*ret;

	if (!(ret = (char *)malloc(num * size)))
		return (0);
	ft_memset(ret, 0, num * size);
	return ((void *)ret);
}
