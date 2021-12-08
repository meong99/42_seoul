/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 17:41:48 by mchae             #+#    #+#             */
/*   Updated: 2020/10/22 19:20:43 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *temp;
	t_list *newlst;

	temp = 0;
	while (lst)
	{
		if (!(newlst = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&temp, (*del));
			return (0);
		}
		ft_lstadd_back(&temp, newlst);
		lst = lst->next;
	}
	return (temp);
}
