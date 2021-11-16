/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:45:49 by mchae             #+#    #+#             */
/*   Updated: 2021/11/16 18:20:38 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exe_env(t_commands *commands)
{
	t_env	*temp;

	temp = g_commands->env;
	while (temp)
	{
		if (temp->value)
		{
			printf("%s=", temp->key);
			printf("%s\n", temp->value);
		}
		temp = temp->next;
	}
	commands = 0;
}
