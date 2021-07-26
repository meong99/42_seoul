/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 19:12:14 by mchae             #+#    #+#             */
/*   Updated: 2021/07/23 15:31:47 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	kill_to_server(int server_pid, int signal)
{
	if (kill(server_pid, signal) == -1)
	{
		write(1, "Transmission error\n", 19);
		exit(-1);
	}
}

static void	send_client_pid(int server_pid)
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

static void	send_strlen(char *str, int server_pid)
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

static void	send_str(char *str, int server_pid)
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

int			main(int ac, char **av)
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
	return (0);
}
