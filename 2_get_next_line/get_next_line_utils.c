/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:47:01 by mchae             #+#    #+#             */
/*   Updated: 2021/09/16 21:12:51 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_buff(t_gnl **head, int fd)
{
	t_gnl	*temp;
	t_gnl	*free_list;

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

t_gnl	*find_buff(t_gnl *lst_buff, int fd)
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

t_gnl	*new_buff(int fd)
{
	t_gnl *new;

	if (!(new = malloc(sizeof(t_gnl))))
		return (0);
	if (!(new->buff = malloc(1)))
		return (0);
	new->buff[0] = '\0';
	new->fd = fd;
	new->next = NULL;
	return (new);
}

size_t	gnl_strlcpy(char *dest, const char *src, size_t size)
{
	size_t i;

	i = 0;
	if ((!dest && !src))
		return (0);
	while (src[i] && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (size)
		dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

size_t	gnl_strlcat(char *dest, const char *src, size_t size)
{
	size_t j;
	size_t i;

	j = 0;
	i = 0;
	while (dest[i] && i < size)
		i++;
	while (src[j] && i + j + 1 < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i + j < size)
		dest[i + j] = '\0';
	while (src[j])
		j++;
	return (i + j);
}
