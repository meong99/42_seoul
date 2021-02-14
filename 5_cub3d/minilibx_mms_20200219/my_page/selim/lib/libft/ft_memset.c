/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selim <selim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 16:12:49 by selim             #+#    #+#             */
/*   Updated: 2020/10/02 16:12:51 by selim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*head;

	head = (unsigned char *)str;
	while (n--)
	{
		*head = (unsigned char)c;
		if (n)
			head++;
	}
	return (str);
}
