/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:46:47 by mchae             #+#    #+#             */
/*   Updated: 2020/10/27 22:07:46 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	free_buff(t_list **head, int fd)
{
	t_list	*temp;
	t_list	*free_list;

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

t_list	*find_buff(t_list *lst_buff, int fd)
{
	t_list *new;

	while (lst_buff)
	{
		if (lst_buff->fd == fd)
			return (lst_buff);
		lst_buff = lst_buff->next;
	}
	if (!(new = new_buff(fd)))
		return (0);
	lst_buff->next = new;
	return (new);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	join_str_len;

	if (!s1 || !s2)
		return (NULL);
	join_str_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(new_str = (char*)malloc(join_str_len)))
		return (NULL);
	ft_strlcpy(new_str, s1, join_str_len);
	ft_strlcat(new_str, s2, join_str_len);
	return (new_str);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
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
