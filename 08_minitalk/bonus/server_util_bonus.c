/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_util_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 17:34:17 by mchae             #+#    #+#             */
/*   Updated: 2021/06/17 14:59:30 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int		print_pid(void)
{
	int		server_pid;
	char	*pid_str;
	int		strlen;

	server_pid = getpid();
	pid_str = ft_itoa(server_pid);
	strlen = ft_strlen(pid_str);
	write(1, "PID : ", 6);
	write(1, pid_str, strlen);
	write(1, "\n", 1);
	free(pid_str);
	pid_str = 0;
	return (1);
}

void	get_client_pid(int *step, int *client_pid, int signal, int *index)
{
	if (*index < 32)
	{
		*client_pid <<= 1;
		*client_pid |= signal;
		(*index)++;
	}
	if (*index == 32)
	{
		*index = 0;
		(*step)++;
	}
}

void	get_strlen(int signal, t_static *static_var)
{
	if (static_var->index < 64)
	{
		static_var->strlen <<= 1;
		static_var->strlen |= signal;
		static_var->index++;
	}
	if (static_var->index == 64)
	{
		static_var->str = ft_malloc(static_var->strlen);
		static_var->step = GET_STR;
		static_var->index = 0;
	}
}

void	save_str(int signal, t_static *static_var)
{
	if (static_var->index < 8)
	{
		static_var->str[static_var->saved] <<= 1;
		static_var->str[static_var->saved] |= signal;
		static_var->index++;
	}
	if (static_var->index == 8)
	{
		static_var->saved++;
		static_var->index = 0;
		if (static_var->saved == static_var->strlen)
			static_var->step = GET_PID_LAST;
	}
}

void	print_and_free(t_static *static_var)
{
	if (static_var->client_pid == static_var->client_pid_last)
	{
		write(1, static_var->str, static_var->strlen);
		write(1, "\n", 1);
		usleep(200);
		kill(static_var->client_pid, SIGUSR1);
	}
	else
	{
		write(1, "Error\nSignal lost\n", 18);
		exit(-1);
	}
	free(static_var->str);
	static_var->str = 0;
	static_var->strlen = 0;
	static_var->saved = 0;
	static_var->client_pid = 0;
	static_var->client_pid_last = 0;
	static_var->step = 0;
}
