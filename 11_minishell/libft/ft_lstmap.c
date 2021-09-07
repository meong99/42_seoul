/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 17:41:48 by mchae             #+#    #+#             */
/*   Updated: 2021/07/08 18:22:25 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*newlst;

	temp = 0;
	while (lst)
	{
		newlst = ft_lstnew((*f)(lst->content));
		if (!newlst)
		{
			ft_lstclear(&temp, (*del));
			return (0);
		}
		ft_lstadd_back(&temp, newlst);
		lst = lst->next;
	}
	return (temp);
}
