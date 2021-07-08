/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 19:12:14 by mchae             #+#    #+#             */
/*   Updated: 2021/06/17 14:59:28 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	reception_check(int signal)
{
	signal = 0;
	write(1, "OK\n", 3);
	exit(0);
}

int		main(int ac, char **av)
{
	int	server_pid;

	if (ac != 3)
	{
		write(1, av[0], ft_strlen(av[0]));
		write(1, " [server PID] [send msg]\n", 25);
		exit(-1);
	}
	server_pid = ft_atoi(av[1]);
	send_client_pid(server_pid);
	send_strlen(av[2], server_pid);
	send_str(av[2], server_pid);
	send_client_pid(server_pid);
	signal(SIGUSR1, reception_check);
	pause();
	return (0);
}
