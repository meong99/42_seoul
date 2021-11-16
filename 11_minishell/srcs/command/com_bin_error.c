/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_bin_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:45:35 by mchae             #+#    #+#             */
/*   Updated: 2021/11/16 19:48:39 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_bin_error(char *com, char *path)
{
	char	*err_msg;
	char	*errstr;

	if (com == NULL)
		return ;
	if (ft_strchr(com, '/') || !path)
		err_msg = "No such file or directory";
	else
		err_msg = "command not found";
	errno = 127;
	errstr = join_errmsg(com, err_msg, 0, 0);
	ft_putstr_fd(errstr, STDERR_FILENO);
	free(errstr);
	exit(errno);
}
