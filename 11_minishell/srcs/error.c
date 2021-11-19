/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:47:20 by mchae             #+#    #+#             */
/*   Updated: 2021/11/19 23:42:37 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_systax_err(char *token)
{
	char	*errstr;

	errstr = ft_strjoin("minishell: ", "syntax error near unexpected token `");
	errstr = ft_strjoin_free(errstr, token);
	errstr = ft_strjoin_free(errstr, "'\n");
	ft_putstr_fd(errstr, STDERR_FILENO);
	free(errstr);
	errno = 258;
	return (RET_ERR_INT);
}

int	closed_quote(char *str)
{
	int		result;
	char	mark;

	result = true;
	while (*str)
	{
		if (*str == '\'' || *str == '\"')
		{
			mark = *str;
			result = false;
			while (!result && *str)
			{
				if (*++str == mark)
					result = true;
			}
		}
		if (*str == 0)
			break ;
		str++;
	}
	if (result == false)
		print_systax_err(&mark);
	return (result);
}

static int	check_after_pipe(char *str)
{
	char	*tmp;

	tmp = str;
	while (1)
	{
		tmp = ft_strchr_f(tmp, '|', BOTH, check_quote);
		if (tmp == 0)
			break ;
		tmp++;
		while (*tmp == ' ')
			tmp++;
		if (*tmp == '|' || *tmp == '\0')
		{
			free(str);
			print_systax_err("|");
			return (1);
		}
	}
	return (0);
}

static int	check_pipe_err(char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '|')
	{
		free(str);
		print_systax_err("|");
		return (1);
	}
	return (check_after_pipe(str));
}

int	check_str_err(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("\x1b[1A\033[11Cexit\n", STDOUT_FILENO);
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
	return (check_pipe_err(str));
}
