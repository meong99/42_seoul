/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 23:22:39 by mchae             #+#    #+#             */
/*   Updated: 2021/11/19 23:40:42 by mchae            ###   ########.fr       */
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
