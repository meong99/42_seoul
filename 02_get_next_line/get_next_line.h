/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:47:06 by mchae             #+#    #+#             */
/*   Updated: 2021/09/16 21:12:34 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include "libft.h"
# define BUFFER_SIZE 10

typedef struct		s_gnl
{
	int				fd;
	char			*buff;
	struct s_gnl	*next;
	char			temp_buff[BUFFER_SIZE + 1];
}					t_gnl;

int					get_next_line(int fd, char **line);
t_gnl				*new_buff(int fd);
t_gnl				*find_buff(t_gnl *lst_buff, int fd);
int					find_new_line(char **line, t_gnl *lst_buf);
size_t				gnl_strlcpy(char *dest, const char *src, size_t size);
char				*gnl_strjoin(char **s1, char *s2);
size_t				gnl_strlcat(char *dest, const char *src, size_t size);
void				free_buff(t_gnl **head, int fd);
void				cpy_buff(t_gnl *lst_buf, char **line, size_t i);
size_t				gnl_strlen(const char *str);

#endif
