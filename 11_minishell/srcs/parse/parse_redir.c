/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 06:59:17 by mchae             #+#    #+#             */
/*   Updated: 2021/11/25 20:22:52 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*parse_target(t_commands *commands, char *end)
{
	if (ft_strncmp(end, "<<", 2) == 0)
		return (parse_heredoc(commands, end));
	else if (ft_strncmp(end, "<", 1) == 0)
		return (parse_less(commands, end));
	else if (ft_strncmp(end, ">>", 2) == 0)
		return (parse_append(commands, end));
	else
		return (parse_greater(commands, end));
}

static char	*parse_redir(t_commands *commands, char *str)
{
	int		i;
	char	*start;
	char	*end;

	i = -1;
	end = str;
	start = 0;
	while (end[++i])
	{
		if (ft_strchr("<>", end[i]) && !check_quote(str, end + i, BOTH))
		{
			end = end + i;
			if (!start)
				start = end;
			end = parse_target(commands, end);
			i = -1;
		}
	}
	if (!start)
		return (ft_strdup(str));
	else
		return (ft_cut(str, start, end));
}

char	*redir_handler(t_commands *commands, char *str)
{
	char	*except_redir;

	except_redir = parse_redir(commands, str);
	return (except_redir);
}
