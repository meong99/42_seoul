/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:47:26 by mchae             #+#    #+#             */
/*   Updated: 2021/11/10 22:57:08 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_errno(char **str)
{
	if (errno || g_commands->com == NULL)
	{
		free_all(str, g_commands->fd);
		return (1);
	}
	return (0);
}

static int	str_handler(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("\x1b[1A", STDOUT_FILENO);
		ft_putstr_fd("\033[11C", STDOUT_FILENO);
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		tcsetattr(STDIN_FILENO, TCSANOW, &g_commands->oldterm);
		exit(0);
	}
	if (*str == 0 || !closed_quote(str))
	{
		free(str);
		return (1);
	}
	if (*str)
		add_history(str);
	return (0);
}

int	loop_minishell(t_env *env, struct termios oldterm)
{
	char	*str;
	int		old_errno;

	while (1)
	{
		old_errno = errno;
		str = readline("\033[1;36mminishell> \033[0m ");
		errno = 0;
		if (str_handler(str))
			continue ;
		parsing_handler(str, old_errno, env);
		g_commands->oldterm = oldterm;
		if (check_errno(&str))
			continue ;
		if (set_commands() == CHILD)
			return (0);
		free_all(&str, g_commands->fd);
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
	loop_minishell(env, oldterm);
	return (0);
}
