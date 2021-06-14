/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:49:09 by mchae             #+#    #+#             */
/*   Updated: 2021/06/14 17:43:55 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_static
{
	char	*str;
	size_t	strlen;
	size_t	saved;
}				t_staitc;

/*
** server_util.c
*/
int		print_pid(void);
size_t	get_strlen(int signal, t_staitc *static_var);
size_t	save_str(int signal, t_staitc *static_var);
void	print_and_free(t_staitc *static_var);

# define GET_STRLEN 0
# define MALLOC 1
# define GET_STR 2

#endif
