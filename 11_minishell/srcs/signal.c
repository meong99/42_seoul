/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:47:18 by mchae             #+#    #+#             */
/*   Updated: 2021/11/24 20:21:54 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_handler(int signal)
{
	if (g_sig_handler[0] == SIG_COM)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		g_sig_handler[1] = 130;
		return ;
	}
	else if (g_sig_handler[0] == SIG_HEREDOC)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		g_sig_handler[0] = AFTER_SIG_HEREDOC;
		close(STDIN_FILENO);
	}
	else
	{
		if (g_sig_handler[0] == SIG_USUAL || \
			g_sig_handler[0] != AFTER_SIG_HEREDOC)
			ft_putstr_fd("\n", STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	g_sig_handler[1] = 1;
	signal = 0;
}

void	sig_quit_handler(int signal)
{
	g_sig_handler[1] = 131;
	ft_putstr_fd("Quit: 3\n", STDERR_FILENO);
	signal = 0;
}
