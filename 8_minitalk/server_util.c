/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 17:34:17 by mchae             #+#    #+#             */
/*   Updated: 2021/06/14 17:43:49 by mchae            ###   ########.fr       */
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

size_t	get_strlen(int signal, t_staitc *static_var)
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
		static_var->str = ft_malloc(ret);
		return (ret);
	}
	return (0);
}

size_t	save_str(int signal, t_staitc *static_var)
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
		static_var->str[static_var->saved] = character;
		static_var->saved++;
		index = 0;
	}
	return (1);
}

void	print_and_free(t_staitc *static_var)
{
	write(1, static_var->str, static_var->strlen);
	write(1, "\n", 1);
	free(static_var->str);
	static_var->str = 0;
	static_var->strlen = 0;
	static_var->saved = 0;
}
