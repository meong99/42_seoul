/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotation_mark.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:46:51 by mchae             #+#    #+#             */
/*   Updated: 2021/11/09 23:20:36 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	get_mark(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (str[i]);
	}
	return (-1);
}

int	check_quote(char *str, char *pointer, int option)
{
	char	mark;
	char	*front;
	char	*back;

	front = str;
	back = str;
	while (front && back)
	{
		mark = get_mark(front);
		if (mark == -1)
			return (false);
		front = ft_strchr(front, mark);
		back = ft_strchr(front + 1, mark);
		if (front && back)
		{
			if (front < pointer && pointer < back && \
			(option == BOTH || (option == SINGLE_QUOTE && mark == '\'') || \
			(option == DOUBLE_QUOTE && mark == '\"')))
				return (true);
		}
		front = back + 1;
	}
	return (false);
}
