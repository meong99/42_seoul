/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:45:46 by mchae             #+#    #+#             */
/*   Updated: 2021/11/10 04:55:52 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_echo(t_list *node, int option)
{
	char	*str;

	while (node)
	{
		str = (char *)node->content;
		if (str == NULL)
			str = "";
		printf("%s", str);
		node = node->next;
		if (node)
			printf(" ");
	}
	if (option == false)
		printf("\n");
}

static int	set_option(t_list *node)
{
	if (node && ft_strncmp((char *)node->content, "-n", 3) == 0)
		return (true);
	return (false);
}

void	exe_echo(t_commands *commands)
{
	t_list	*node;
	int		option;

	node = commands->arg;
	option = set_option(node);
	print_echo(node + option, option);
}
