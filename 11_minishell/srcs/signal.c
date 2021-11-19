/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:47:18 by mchae             #+#    #+#             */
/*   Updated: 2021/11/19 23:17:50 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_handler(int signal)
{
	if (!g_commands || g_commands->sig_handle == true)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (g_commands->sig_handle == false)
		ft_putstr_fd("\n", STDOUT_FILENO);
	else if (g_commands->sig_handle == HEREDOC)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		g_commands->sig_handle = true;
		close(STDIN_FILENO);
	}
	errno = 1;
	signal = 0;
}
