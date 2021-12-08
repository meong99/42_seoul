/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:47:06 by mchae             #+#    #+#             */
/*   Updated: 2021/03/27 20:20:08 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 10

typedef struct		s_gnl_lst
{
	int					fd;
	char				*buff;
	struct s_gnl_lst	*next;
	char				temp_buff[BUFFER_SIZE + 1];
}					t_gnl_lst;

int					get_next_line(int fd, char **line);
t_gnl_lst			*new_buff(int fd);
t_gnl_lst			*find_buff(t_gnl_lst *lst_buff, int fd);
int					find_new_line(char **line, t_gnl_lst *lst_buf);
size_t				gnl_ft_strlcpy(char *dest, const char *src, size_t size);
char				*gnl_ft_strjoin(char **s1, char *s2);
size_t				gnl_ft_strlcat(char *dest, const char *src, size_t size);
void				free_buff(t_gnl_lst **head, int fd);
void				cpy_buff(t_gnl_lst *lst_buf, char **line, size_t i);
size_t				gnl_ft_strlen(const char *str);

#endif
