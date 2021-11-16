/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:47:20 by mchae             #+#    #+#             */
/*   Updated: 2021/11/16 20:14:26 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_errmsg(char *str1, char *str2, char *str3, char *str4)
{
	char	*str;

	str = ft_strdup("minishell: ");
	if (str1)
		str = ft_strjoin_free(str, str1);
	if (str2)
	{
		str = ft_strjoin_free(str, ": ");
		str = ft_strjoin_free(str, str2);
	}
	if (str3)
	{
		str = ft_strjoin_free(str, ": ");
		str = ft_strjoin_free(str, str3);
	}
	if (str4)
	{
		str = ft_strjoin_free(str, ": ");
		str = ft_strjoin_free(str, str4);
	}
	str = ft_strjoin_free(str, "\n");
	return (str);
}

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

void	put_err(char *source_err, int use_exit)
{
	char	*errstr;

	errstr = strerror(errno);
	errstr = join_errmsg(source_err, errstr, 0, 0);
	ft_putstr_fd(errstr, STDERR_FILENO);
	free(errstr);
	if (use_exit)
		exit(errno);
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

int	check_str_err(char *str)
{
	int	i;

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
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '|')
	{
		free(str);
		print_systax_err("|");
		return (1);
	}
	return (0);
}
