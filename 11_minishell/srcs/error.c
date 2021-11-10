/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:47:20 by mchae             #+#    #+#             */
/*   Updated: 2021/11/10 22:54:34 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_systax_err(char *token)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd("syntax error near unexpected token `", STDERR_FILENO);
	if (*token == '<' || *token == '>')
		ft_putstr_fd(token, STDERR_FILENO);
	else
		write(STDERR_FILENO, token, 1);
	ft_putstr_fd("'\n", STDERR_FILENO);
	errno = 258;
	return (RET_ERR_INT);
}

void	put_err(char *source_err, int use_exit)
{
	char	*str_err;

	str_err = strerror(errno);
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(source_err, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(str_err, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
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
