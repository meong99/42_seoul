/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_util_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 23:35:16 by mchae             #+#    #+#             */
/*   Updated: 2021/06/16 23:42:28 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	kill_to_server(int server_pid, int signal)
{
	if (kill(server_pid, signal) == -1)
	{
		write(1, "Transmission error\n", 19);
		exit(-1);
	}
}

void	send_client_pid(int server_pid)
{
	int				client_pid;
	unsigned int	bit;

	bit = 1;
	bit <<= 31;
	client_pid = getpid();
	while (bit)
	{
		if (client_pid & bit)
			kill_to_server(server_pid, SIGUSR1);
		else
			kill_to_server(server_pid, SIGUSR2);
		bit >>= 1;
		usleep(100);
	}
}

void	send_strlen(char *str, int server_pid)
{
	size_t	strlen;
	size_t	bit;

	bit = 1;
	bit <<= 63;
	strlen = ft_strlen(str);
	while (bit)
	{
		if (strlen & bit)
			kill_to_server(server_pid, SIGUSR1);
		else
			kill_to_server(server_pid, SIGUSR2);
		bit >>= 1;
		usleep(100);
	}
}

void	send_str(char *str, int server_pid)
{
	unsigned char	bit;

	bit = 1;
	bit <<= 7;
	while (*str)
	{
		while (bit)
		{
			if (*str & bit)
				kill_to_server(server_pid, SIGUSR1);
			else
				kill_to_server(server_pid, SIGUSR2);
			bit >>= 1;
			usleep(100);
		}
		str++;
		bit = 1;
		bit <<= 7;
	}
}
