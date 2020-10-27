/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 21:02:58 by mchae             #+#    #+#             */
/*   Updated: 2020/10/27 22:11:34 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int		find_new_line(char **line, t_list *lst_buf)
{
	size_t	i;
	size_t	j;
	int		find;

	find = 0;
	i = 0;
	j = 0;
	while (lst_buf->buff[i] != '\0')
		if (lst_buf->buff[i++] == '\n')
		{
			find = 1;
			*line = malloc(i);
			ft_strlcpy(*line, lst_buf->buff, i);
			break ;
		}
	if (find)
		while (lst_buf->buff[i])
		{
			lst_buf->buff[j++] = lst_buf->buff[i++];
			lst_buf->buff[j] = '\0';
		}
	return (find);
}

t_list	*new_buff(int fd)
{
	t_list *new;

	if (!(new = (t_list *)malloc(sizeof(t_list *))))
		return (0);
	if (!(new->buff = malloc(BUFFER_SIZE + 1)))
		return (0);
	new->buff[0] = 0;
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
	char			temp_buff[BUFFER_SIZE + 1];
	char			*temp;
	int				size;

	size = 0;
	if (BUFFER_SIZE <= 0 || (!head && !(head = new_buff(fd))) ||
		!(lst_buf = find_buff(head, fd)))
		return (-1);
	while ((size = read(fd, temp_buff, BUFFER_SIZE)) > 0)
	{
		temp = lst_buf->buff;
		lst_buf->buff = ft_strjoin(lst_buf->buff, temp_buff);
		free(temp);
		if (find_new_line(line, lst_buf))
			return (1);
	}
	free_buff(&head, fd);
	return (0);
}

int main(void)
{
	int fd = open("asd.txt", O_RDONLY);
	char *asd;
	asd = 0;
	printf("%d", get_next_line(fd, &asd));
	printf("%s\n", asd);
	printf("%d", get_next_line(fd, &asd));
	printf("%s\n", asd);
	printf("%d", get_next_line(fd, &asd));
	printf("%s\n", asd);
	printf("%d", get_next_line(fd, &asd));
	printf("%s\n", asd);
}
