/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:45:44 by mchae             #+#    #+#             */
/*   Updated: 2021/11/16 19:41:15 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_err_cd(int err_code, char *arg)
{
	char	*errstr;

	if (err_code == 0)
		return ;
	errstr = strerror(errno);
	errstr = join_errmsg("cd", arg, errstr, 0);
	ft_putstr_fd(errstr, STDERR_FILENO);
	free(errstr);
}

void	exe_cd(t_commands *commands)
{
	char	*pwd;
	char	*str;
	int		err_code;

	pwd = getcwd(NULL, 0);
	if (commands->arg)
		str = (char *)commands->arg->content;
	else
		str = "./";
	err_code = chdir(str);
	print_err_cd(err_code, str);
	free(pwd);
}
