/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:47:28 by mchae             #+#    #+#             */
/*   Updated: 2021/11/24 19:44:37 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	terminal_handler(struct termios *oldterm)
{
	struct termios	newterm;

	tcgetattr(STDIN_FILENO, oldterm);
	tcgetattr(STDIN_FILENO, &newterm);
	newterm.c_lflag &= ~ECHOCTL;
	newterm.c_cc[VKILL] = 0;
	newterm.c_cc[VSUSP] = 0;
	newterm.c_cc[VQUIT] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &newterm);
	return (0);
}

int	restore_signal(void)
{
	struct termios	newterm;

	tcgetattr(STDIN_FILENO, &newterm);
	newterm.c_lflag &= ~ECHOCTL;
	newterm.c_cc[VQUIT] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &newterm);
	return (0);
}

int	accept_signal(void)
{
	struct termios	newterm;

	tcgetattr(STDIN_FILENO, &newterm);
	newterm.c_lflag |= ECHOCTL;
	newterm.c_cc[VQUIT] = 28;
	tcsetattr(STDIN_FILENO, TCSANOW, &newterm);
	return (0);
}
