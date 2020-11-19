/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:52:14 by mchae             #+#    #+#             */
/*   Updated: 2020/11/19 21:48:27 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BONUS_FLAGS "# +"
# define FORMAT_D_I_U_X_XX "diuxX"
# define FORMAT "cspdiuxX%"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <wchar.h>
# include "libft/libft.h"
#include <stdio.h>

typedef struct	s_info
{
	char			flag;
	char			bonus_flasg;
	int				width;
	int				precision;
	char			format;
	char			*variable;
	char			minus;
	int				dot;
	char			bonus_format;
}				t_info;
/*
**ft_printf.c
*/
void			initialization_info(t_info *node);
int				ft_printf(const char *str, ...);
int				start_printf(const char *str, va_list ap);
int				parsing_print(const char **str, va_list ap, t_info *info);
void			clean_up(t_info *info);
/*
**ft_parsing_page.c
*/
void			parsing_flag(const char **str, t_info *node);
void			parsing_wid(const char **str, va_list ap, t_info *info);
void			parsing_pre(const char **str, va_list ap, t_info *info);
void			parsing_format(const char **str, t_info *info);
void			parsing_varialbe(va_list ap, t_info *node);
/*
**ft_parsing_variable.c
*/
void			parsing_varialbe_str(char *str, t_info *node);
void			parsing_varialbe_integer(long number, t_info *node);
int				get_va_datatype(int number, t_info *info);
void			parsing_varialbe_char(char c, t_info *node);
void			parsing_varialbe_pointer(size_t pointer, t_info *node);
/*
**ft_itoa_base
*/
char			*ft_itoa_base(size_t num, char format, int div_num);
/*
**ft_print_page.c
*/
int				print_conversions(t_info *head);
int				put_flag(t_info *node);
int				printf_left(t_info *node);
int				print_right(t_info *node);
void			get_width(t_info *node);
/*
**ft_bonus_variable.c
*/

#endif
