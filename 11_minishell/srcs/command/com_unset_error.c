/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_unset_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:46:18 by mchae             #+#    #+#             */
/*   Updated: 2021/11/16 20:14:44 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_err_unset(int err_num, char *arg, char *err_msg)
{
	char	*errstr;

	errno = err_num;
	errstr = "minishell: unset: `";
	errstr = ft_strjoin(errstr, arg);
	errstr = ft_strjoin_free(errstr, "': ");
	errstr = ft_strjoin_free(errstr, err_msg);
	errstr = ft_strjoin_free(errstr, "\n");
	ft_putstr_fd(errstr, STDERR_FILENO);
	free(errstr);
}

int	check_unset_error(char *key)
{
	int		is_err;

	is_err = 0;
	if (!ft_isalpha(*key) && *key != '_' && ++is_err)
		print_err_unset(1, key, "not a valid identifier");
	while (*++key)
	{
		if (ft_isalnum(*key) == 0 && *key != '_' && ++is_err)
			print_err_unset(1, key, "not a valid identifier");
	}
	if (is_err == true)
		return (RET_ERR_INT);
	else
		return (0);
}
