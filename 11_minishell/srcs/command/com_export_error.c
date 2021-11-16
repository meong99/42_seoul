/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_export_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:45:58 by mchae             #+#    #+#             */
/*   Updated: 2021/11/16 19:53:37 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_err_export(int err_num, char *arg, char *err_msg)
{
	char	*errstr;

	errno = err_num;
	errstr = ft_strjoin("minishell: export: `", arg);
	errstr = ft_strjoin_free(errstr, "': ");
	errstr = ft_strjoin_free(errstr, err_msg);
	errstr = ft_strjoin_free(errstr, "\n");
	ft_putstr_fd(errstr, STDERR_FILENO);
	free(errstr);
}

static int	check_key(char *key, char *arg)
{
	while (*++key)
	{
		if (ft_isalnum(*key) == 0 && *key != '_')
		{
			print_err_export(1, arg, "not a valid identifier");
			return (RET_ERR_INT);
		}
	}
	return (0);
}

int	check_first_char(char *str)
{
	if (!ft_isalpha(*str) && *str != '_')
	{
		print_err_export(1, str, "not a valid identifier");
		return (RET_ERR_INT);
	}
	return (0);
}

int	check_export_error(char *key, char *arg)
{
	int		is_err;

	is_err = check_first_char(key);
	is_err = check_key(key, arg);
	if (is_err == RET_ERR_INT)
		return (RET_ERR_INT);
	else
		return (0);
}
