/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:49:09 by mchae             #+#    #+#             */
/*   Updated: 2021/06/16 23:42:56 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include "libft.h"

# define GET_STRLEN 0
# define MALLOC 1
# define GET_STR 2
# define GET_PID 0
# define GET_LEN 1
# define GET_STR 2
# define GET_PID_LAST 3
# define PRINT_FREE 4

typedef struct	s_static
{
	char	*str;
	size_t	strlen;
	size_t	saved;
	int		client_pid;
	int		client_pid_last;
	int		step;
	int		index;
}				t_static;
/*
** server_util.c
*/
int				print_pid(void);
void			get_strlen(int signal, t_static *static_var);
void			save_str(int signal, t_static *static_var);
void			print_and_free(t_static *static_var);
void			get_client_pid(int *step,\
int *client_pid, int signal, int *index);

/*
** client_util.c
*/
void			kill_to_server(int server_pid, int signal);
void			send_client_pid(int server_pid);
void			send_strlen(char *str, int server_pid);
void			send_str(char *str, int server_pid);

#endif
