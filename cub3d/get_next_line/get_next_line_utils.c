/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:47:01 by mchae             #+#    #+#             */
/*   Updated: 2020/10/29 08:00:40 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_buff(t_gnl_lst **head, int fd)
{
	t_gnl_lst	*temp;
	t_gnl_lst	*free_list;

	temp = *head;
	if (temp->fd == fd)
	{
		*head = temp->next;
		free(temp->buff);
		free(temp);
		return ;
	}
	while (temp->next->fd != fd)
		temp = temp->next;
	free_list = temp->next;
	temp->next = free_list->next;
	free(free_list->buff);
	free(free_list);
}

t_gnl_lst	*find_buff(t_gnl_lst *lst_buff, int fd)
{
	while (lst_buff)
	{
		if (lst_buff->fd == fd)
			break ;
		if (lst_buff->next == NULL)
			if (!(lst_buff->next = new_buff(fd)))
				return (0);
		lst_buff = lst_buff->next;
	}
	return (lst_buff);
}

t_gnl_lst	*new_buff(int fd)
{
	t_gnl_lst *new;

	if (!(new = malloc(sizeof(t_gnl_lst))))
		return (0);
	if (!(new->buff = malloc(1)))
		return (0);
	new->buff[0] = '\0';
	new->fd = fd;
	new->next = NULL;
	return (new);
}
