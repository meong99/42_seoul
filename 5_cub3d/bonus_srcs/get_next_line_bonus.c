/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:47:04 by mchae             #+#    #+#             */
/*   Updated: 2021/03/27 20:11:00 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*gnl_ft_strjoin(char **s1, char *s2)
{
	char	*new_str;
	size_t	join_str_len;

	if (!s1 || !s2)
		return (NULL);
	join_str_len = gnl_ft_strlen(*s1) + gnl_ft_strlen(s2) + 1;
	if (!(new_str = (char*)malloc(join_str_len)))
		return (NULL);
	gnl_ft_strlcpy(new_str, *s1, join_str_len);
	gnl_ft_strlcat(new_str, s2, join_str_len);
	free(*s1);
	return (new_str);
}

int		find_new_line(char **line, t_gnl_lst *lst_buf)
{
	size_t	i;
	size_t	j;
	int		found;

	found = 0;
	i = 0;
	j = 0;
	while (lst_buf->buff[i] != '\0')
		if (lst_buf->buff[i++] == '\n')
		{
			found = 1;
			*line = malloc(i);
			gnl_ft_strlcpy(*line, lst_buf->buff, i);
			break ;
		}
	if (found)
		gnl_ft_strlcpy(lst_buf->buff, lst_buf->buff + i,
					gnl_ft_strlen(lst_buf->buff) + 1);
	return (found);
}

int		get_next_line(int fd, char **line)
{
	static t_gnl_lst	*head;
	t_gnl_lst			*lst_buf;
	ssize_t				size;
	int					found;

	if (BUFFER_SIZE <= 0 || !line || (!head && !(head = new_buff(fd))) || \
		!(lst_buf = find_buff(head, fd)))
		return (-1);
	*line = 0;
	while (!(found = find_new_line(line, lst_buf)) && \
		((size = read(fd, lst_buf->temp_buff, BUFFER_SIZE)) > 0))
	{
		lst_buf->temp_buff[size] = '\0';
		lst_buf->buff = gnl_ft_strjoin(&(lst_buf->buff), lst_buf->temp_buff);
	}
	if (found)
		return (found);
	if (size < 0)
		return (-1);
	*line = malloc(gnl_ft_strlen(lst_buf->buff) + 1);
	gnl_ft_strlcpy(*line, lst_buf->buff, gnl_ft_strlen(lst_buf->buff) + 1);
	free_buff(&head, fd);
	return (0);
}
