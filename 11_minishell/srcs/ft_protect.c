/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_protect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:47:24 by mchae             #+#    #+#             */
/*   Updated: 2021/11/08 23:47:24 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_protect(void *arg)
{
	if (arg == NULL && errno)
	{
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		exit(errno);
	}
}
