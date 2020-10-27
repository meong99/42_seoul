/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:47:06 by mchae             #+#    #+#             */
/*   Updated: 2020/10/27 18:45:18 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	int				fd;
	char			buff[BUFFER_SIZE + 1];
	struct s_list	*next;
}					t_list;

int					get_next_line(int fd, char **line);
t_list				*new_buff(int fd);
t_list				*find_buff(t_list *lst_buff, int fd);
int					find_new_line(t_list *lst_buf, char **list);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
void				free_buff(t_list **head, int fd);
void				cpy_buff(t_list *lst_buf, char **line, size_t i);
size_t				ft_strlen(const char *str);

#endif
