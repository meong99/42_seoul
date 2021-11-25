/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:46:47 by mchae             #+#    #+#             */
/*   Updated: 2021/11/25 21:18:30 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_space(t_commands *commands, char *str)
{
	char	**spl;
	char	*mapped;
	int		i;

	spl = ft_split_f(str, ' ', BOTH, check_quote);
	ft_protect(spl);
	i = -1;
	while (spl[++i])
	{
		mapped = mapping_dollar(commands, spl[i], commands->old_errno);
		if (commands->com == NULL)
			commands->com = mapped;
		else if (mapped)
			ft_lstadd_back(&commands->arg, ft_lstnew(mapped));
		free(spl[i]);
	}
	free(spl);
}
