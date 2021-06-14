/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 19:12:14 by mchae             #+#    #+#             */
/*   Updated: 2021/06/14 14:20:10 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_strlen(char *str, int server_pid)
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
	return (1);
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

int	main(int ac, char **av)
{
	int	server_pid;

	server_pid = ft_atoi(av[1]);
	send_strlen(av[2], server_pid);
	send_str(av[2], server_pid);
	return (0);
}
