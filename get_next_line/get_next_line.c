/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:47:04 by mchae             #+#    #+#             */
/*   Updated: 2020/10/27 18:02:15 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		find_new_line(t_list *lst_buf, char **line)
{
	size_t	i;
	int		find;

	find = 0;
	i = 0;
	while (lst_buf->buff[i] != '\0')
	{
		i++;
		if (lst_buf->buff[i] == '\n')
		{
			find = 1;
			break ;
		}
	}
	cpy_buff(lst_buf, line, i);
	return (find);
}

void	cpy_buff(t_list *lst_buf, char **line, size_t i)
{
	char	*temp;
	size_t	j;

	j = 0;
	if (!*line)
	{
		*line = malloc(i + 1);
		ft_strlcpy(*line, lst_buf->buff, i + 1);
	}
	else
	{
		temp = *line;
		*line = ft_strjoin(*line, lst_buf->buff);
		free(temp);
	}
	while (lst_buf->buff[i])
		lst_buf->buff[j++] = lst_buf->buff[i++];
}

t_list	*new_buff(int fd)
{
	t_list *new;

	if (!(new = (t_list *)malloc(sizeof(t_list *))))
		return (0);
	if (!(new->buff = malloc(sizeof(char*) * BUFFER_SIZE + 1)))
		return (0);
	new->fd = fd;
	new->next = NULL;
	return (new);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}


int		get_next_line(int fd, char **line)
{
	static t_list	*head;
	t_list			*lst_buf;
	int				size;

	size = 0;
	if (!head)
		if (!(head = new_buff(fd)))
			return (-1);
	if (!(lst_buf = find_buff(head, fd)))
		return (-1);
	while ((size = read(fd, lst_buf->buff, BUFFER_SIZE) > 0))
	{
		lst_buf->buff[size] = '\0';
		if (find_new_line(lst_buf, line))
			return (1);
	}
	free_buff(&head, fd);
	return (0);
}
