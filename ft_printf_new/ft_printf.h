/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:52:14 by mchae             #+#    #+#             */
/*   Updated: 2020/11/15 21:45:11 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include "libft/libft.h"
#include <stdio.h>

typedef struct	s_info
{
	char			flags;
	int				width;
	int				precision;
	char			format;
	char			sign;
	char			*variable;
	char			minus;
}				t_info;

t_info			*new_list();
int				ft_printf(const char *str, ...);
int				get_format_specifier(const char *str, va_list ap, t_info *info);
int				print(const char **str, va_list ap, t_info *info);
int				lets_print(t_info *head);

void			parsing_flag(const char **str, t_info *node);
void			parsing_wid(const char **str, va_list ap, t_info *info);
void			parsing_pre(const char **str, va_list ap, t_info *info);
void			parsing_varialbe(va_list ap, t_info *node);
void			parsing_varialbe_str(char *str, t_info *node);
void			parsing_varialbe_integer(int number, t_info *node);
void			parsing_varialbe_char(char c, t_info *node);
void			parsing_varialbe_pointer(size_t pointer, t_info *node);

char			*ft_itoa_base(size_t num, char format, int div_num);

int				put_integer(t_info *node);
int				put_flag(t_info *node);
int				left_sort(t_info *node);
int				right_sort(t_info *node);
int				get_variable_len(t_info *node);
void			clean_up(t_info *info);
int				print_d_i(t_info *node);
void	get_print_width(t_info *node);

#endif
