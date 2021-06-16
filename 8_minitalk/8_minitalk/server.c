/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 21:58:22 by mchae             #+#    #+#             */
/*   Updated: 2021/06/16 13:47:54 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	arrange_bit(t_static *static_var, int signal)
{
	if (static_var->step == GET_PID)
		get_client_pid(static_var->step, static_var->client_pid, signal);
	else if (static_var->step == GET_LEN)
		get_strlen(signal, static_var);
	else if (static_var->step == GET_STR)
		save_str(signal, static_var);
	else if (static_var->step == GET_PID_LAST)
		get_client_pid(static_var->step, static_var->client_pid_last, signal);
	else if (static_var->step == PRINT_FREE)
		print_and_free(static_var);
}

void	save_bit(int sigusr)
{
	static t_static	static_var;
	int				signal;

	if (sigusr == SIGUSR1)
		signal = 1;
	else
		signal = 0;
	arrange_bit(&static_var, signal);
}

int		main(void)
{
	print_pid();
	while (1)
	{
		signal(SIGUSR1, save_bit);
		signal(SIGUSR2, save_bit);
		pause();
	}
	return (0);
}
