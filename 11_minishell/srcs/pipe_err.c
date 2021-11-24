/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:47:20 by mchae             #+#    #+#             */
/*   Updated: 2021/11/22 06:37:29 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_after_pipe(char *str)
{
	char	*tmp;

	tmp = str;
	while (1)
	{
		tmp = ft_strchr_f(tmp, '|', BOTH, check_quote);
		if (tmp == 0)
			break ;
		tmp++;
		while (*tmp == ' ')
			tmp++;
		if (*tmp == '|' || *tmp == '\0')
		{
			free(str);
			print_systax_err("|");
			return (1);
		}
	}
	return (0);
}

int	check_pipe_err(char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '|')
	{
		free(str);
		print_systax_err("|");
		return (1);
	}
	return (check_after_pipe(str));
}
