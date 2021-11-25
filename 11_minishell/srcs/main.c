/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:47:26 by mchae             #+#    #+#             */
/*   Updated: 2021/11/25 20:32:03 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	loop_minishell(t_env *env, struct termios oldterm)
{
	char		*str;
	int			old_errno;
	t_commands	*commands;

	while (1)
	{
		old_errno = errno;
		str = readline("\033[1;36mminishell> \033[0m ");
		errno = 0;
		if (g_sig_handler[1])
		{
			old_errno = g_sig_handler[1];
			g_sig_handler[1] = 0;
		}
		if (check_str_err(oldterm, str))
			continue ;
		commands = parsing_handler(str, old_errno, env);
		commands->oldterm = oldterm;
		if (set_commands(commands) == CHILD)
			return (0);
		env = commands->env;
		free_all(commands, &str, commands->fd);
	}
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_env			*env;
	struct termios	oldterm;

	if (ac == 0 || av == NULL || envp == NULL)
		return (0);
	env = init_env_var(envp);
	terminal_handler(&oldterm);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_quit_handler);
	loop_minishell(env, oldterm);
	return (0);
}
