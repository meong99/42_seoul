/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:45:56 by mchae             #+#    #+#             */
/*   Updated: 2021/11/16 19:58:59 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_err_exit(void)
{
	char	*errstr;

	errstr = ft_strjoin("exit\n", "minishell: ");
	errstr = ft_strjoin_free(errstr, "exit: ");
	errstr = ft_strjoin_free(errstr, "too many arguments\n");
	ft_putstr_fd(errstr, STDERR_FILENO);
	free(errstr);
	errno = 1;
}

static int	ret_arg_len(t_list *arg)
{
	int	i;

	i = 0;
	while (arg && ++i)
		arg = arg->next;
	return (i);
}

static int	check_numeric(t_list *arg)
{
	char	*str;

	while (arg)
	{
		str = (char *)arg->content;
		while (*str)
		{
			if (ft_isdigit(*str) == 0)
				return (false);
			str++;
		}
		arg = arg->next;
	}
	return (true);
}

void	exe_exit(t_list *arg)
{
	char	*errstr;

	if (check_numeric(arg) == false)
	{
		errstr = ft_strjoin("exit\n", "minishell: ");
		errstr = ft_strjoin_free(errstr, "exit: ");
		errstr = ft_strjoin_free(errstr, (char *)arg->content);
		errstr = ft_strjoin_free(errstr, ": numeric argument required\n");
		ft_putstr_fd(errstr, STDERR_FILENO);
		free(errstr);
		errno = 255;
		tcsetattr(STDIN_FILENO, TCSANOW, &g_commands->oldterm);
		exit(errno);
	}
	else if (ret_arg_len(arg) > 1)
		print_err_exit();
	else
	{
		if (arg)
			errno = ft_atoi((char *)arg->content);
		else
			errno = g_commands->old_errno;
		tcsetattr(STDIN_FILENO, TCSANOW, &g_commands->oldterm);
		exit(errno);
	}
}
