/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:46:16 by mchae             #+#    #+#             */
/*   Updated: 2021/11/08 23:46:16 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exe_pwd(void)
{
	char	*str;

	str = getcwd(NULL, 0);
	ft_protect(str);
	printf("%s\n", str);
	free(str);
}
