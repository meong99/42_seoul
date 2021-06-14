/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 21:58:22 by mchae             #+#    #+#             */
/*   Updated: 2021/06/14 15:51:23 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		print_pid(void)
{
	int		pid;
	char	*pid_str;
	int		strlen;

	pid = getpid();
	pid_str = ft_itoa(pid);
	strlen = ft_strlen(pid_str);
	write(1, "PID : ", 6);
	write(1, pid_str, strlen);
	write(1, "\n", 1);
	free(pid_str);
	pid_str = 0;
	return (1);
}

size_t	get_strlen(int signal, char **str)
{
	static int		index;
	static size_t	strlen;
	size_t			ret;

	if (index != 64)
	{
		strlen <<= 1;
		strlen |= signal;
		index++;
	}
	if (index == 64)
	{
		index = 0;
		ret = strlen;
		strlen = 0;
		*str = ft_malloc(ret);
		return (ret);
	}
	return (0);
}

size_t	save_str(int signal, char *str, size_t *saved)
{
	static int		index;
	static char		character;

	if (index != 8)
	{
		character <<= 1;
		character |= signal;
		index++;
	}
	if (index == 8)
	{
		str[*saved] = character;
		(*saved)++;
		index = 0;
	}
	return (1);
}

void	save_bit(int sigusr)
{
	static char		*str;
	static size_t	strlen;
	static size_t	saved;
	int				signal;

	if (sigusr == SIGUSR1)
		signal = 1;
	else
		signal = 0;
	if (!strlen)
		strlen = get_strlen(signal, &str);
	else if (saved != strlen)
		save_str(signal, str, &saved);
	if (strlen && saved == strlen)
	{
		write(1, str, strlen);
		write(1, "\n", 1);
		free(str);
		str = 0;
		strlen = 0;
		saved = 0;
	}
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
