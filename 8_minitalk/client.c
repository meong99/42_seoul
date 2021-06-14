/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 19:12:14 by mchae             #+#    #+#             */
/*   Updated: 2021/06/15 01:46:07 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_client_pid(int server_pid)
{
	int	client_pid;
	int	bit;

	bit = 1;
	bit <<= 31;
	client_pid = getpid();
	while (bit)
	{
		if (client_pid & bit)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
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
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
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
			{
				kill(server_pid, SIGUSR1);
			}
			else
			{
				kill(server_pid, SIGUSR2);
			}
			bit >>= 1;
			usleep(100);
		}
		str++;
		bit = 1;
		bit <<= 7;
	}
}

int		main(int ac, char **av)
{
	int	server_pid;

	if (ac < 3)
	{
		write(1, av[0], ft_strlen(av[0]));
		write(1, " [server PID] [send msg]\n", 25);
		exit(-1);
	}
	server_pid = ft_atoi(av[1]);
	send_client_pid(server_pid);
	send_strlen(av[2], server_pid);
	send_str(av[2], server_pid);
	return (0);
}
