/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 06:59:06 by mchae             #+#    #+#             */
/*   Updated: 2021/11/22 18:24:41 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_pipe(char **spl)
{
	int			pipe_num;
	int			i;

	pipe_num = 0;
	if (g_commands)
		free(g_commands);
	while (spl[pipe_num])
		pipe_num++;
	g_commands = malloc(sizeof(t_commands) * pipe_num);
	ft_protect(g_commands);
	i = -1;
	while (++i < pipe_num)
	{
		g_commands[i].command_num = pipe_num;
		g_commands[i].index = i;
	}
}
