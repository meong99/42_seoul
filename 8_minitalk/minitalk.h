/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:49:09 by mchae             #+#    #+#             */
/*   Updated: 2021/06/15 01:37:33 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include "libft/libft.h"

# define GET_STRLEN 0
# define MALLOC 1
# define GET_STR 2
# define GET_PID 0
# define GET_LEN 1
# define GET_STR 2
# define PRINT_FREE 3

typedef struct	s_static
{
	char	*str;
	size_t	strlen;
	size_t	saved;
	int		client_pid;
	int		step;
}				t_static;

/*
** server_util.c
*/
int		print_pid(void);
void	get_strlen(int signal, t_static *static_var);
void	save_str(int signal, t_static *static_var);
void	print_and_free(t_static *static_var);
void	get_client_pid(t_static *static_var, int signal);

#endif
