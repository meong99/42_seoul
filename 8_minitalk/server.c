/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 21:58:22 by mchae             #+#    #+#             */
/*   Updated: 2021/06/14 17:45:05 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	arrange_bit(t_staitc *static_var, int signal)
{
	if (!static_var->strlen)
		static_var->strlen = get_strlen(signal, static_var);
	else if (static_var->saved != static_var->strlen)
		save_str(signal, static_var);
	if (static_var->strlen && static_var->saved == static_var->strlen)
		print_and_free(static_var);
}

void	save_bit(int sigusr)
{
	static t_staitc	static_var;
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
