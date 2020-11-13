/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:52:14 by mchae             #+#    #+#             */
/*   Updated: 2020/11/13 21:08:12 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include "libft/libft.h"
# include <stdio.h>//											asdasdasdasdasdasdasdasdasdasdasdasdasdasdasdasds

typedef struct	s_info
{
	char			flags;
	int				width;
	char			sign;
	int				precision;
	char			format;
	struct s_info	*next;
	char			*variable;
}				t_info;

t_info	*new_list();
t_info	*find_end_list(t_info **head);
void	free_node(t_info **node);
int		ft_printf(const char *str, ...);
void	get_format_specifier(const char *str, va_list ap, t_info **head);
void	parsing(const char **str, va_list ap, t_info **head);
int		lets_print(t_info *head, const char *str);

void	parsing_flag(const char **str, t_info *node);
void	parsing_wid_or_pre(const char **str, int *wid_or_precision, va_list ap);
void	parsing_format(const char **str, t_info *node);
void	parsing_varialbe(va_list ap, t_info *node);
void	parsing_varialbe_str(char *str, t_info *node);
void	parsing_varialbe_integer(int number, t_info *node);
void	parsing_varialbe_char(char c, t_info *node);
void	parsing_varialbe_pointer(size_t pointer, t_info *node);

char	*ft_itoa_base(size_t num, char format, int div_num);

int		left_sort(t_info *node);
int		right_sort(t_info *node);
int		put_integer(t_info *node);
int		get_variable_len(t_info *node);

#endif
