/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_unset_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:46:18 by mchae             #+#    #+#             */
/*   Updated: 2021/11/08 23:46:21 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_err_unset(int err_num, char *arg, char *err_mag)
{
	errno = err_num;
	ft_putstr_fd("minishell: unset: `", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd("': ", STDERR_FILENO);
	ft_putstr_fd(err_mag, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
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
