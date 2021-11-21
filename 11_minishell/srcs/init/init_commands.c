/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:49:57 by mchae             #+#    #+#             */
/*   Updated: 2021/11/22 06:39:43 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_commands(t_commands *commands, t_env *env)
{
	commands->com = NULL;
	commands->arg = NULL;
	commands->redir_lst_mark = NULL;
	commands->redir_lst_target = NULL;
	commands->redir_in = NULL;
	commands->redir_out = NULL;
	commands->redir_input = NULL;
	commands->redir_out_file = NULL;
	commands->env = env;
}
