/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 06:59:17 by mchae             #+#    #+#             */
/*   Updated: 2021/11/16 19:41:05 by mchae            ###   ########.fr       */
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
		if (errno)
			break ;
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

static void	parse_mapped(t_commands *commands, char *mapped, char *mark)
{
	char	*input;

	if (*mark == '<')
	{
		free(commands->redir_input);
		free(commands->redir_in);
		commands->redir_in = ft_strdup(mark);
		if (ft_strncmp(commands->redir_in, "<", 2) == 0)
		{
			input = redir_input(mapped);
			commands->redir_input = input;
			free(mapped);
		}
		else
			commands->redir_input = mapped;
	}
	else
	{
		free(commands->redir_out);
		free(commands->redir_out_file);
		commands->redir_out = ft_strdup(mark);
		commands->redir_out_file = mapped;
		make_file(mapped, commands);
	}
}

static void	mapping_redir(t_commands *commands)
{
	t_list	*mark;
	t_list	*target;
	char	*mapped;

	mark = commands->redir_lst_mark;
	target = commands->redir_lst_target;
	while (mark)
	{
		mapped = mapping_dollar((char *)target->content, commands->old_errno);
		if (mapped == NULL)
		{
			errno = 1;
			mapped = join_errmsg((char *)target->content, \
				"ambiguous redirect", 0, 0);
			ft_putstr_fd(mapped, STDERR_FILENO);
			free(mapped);
			return ;
		}
		parse_mapped(commands, mapped, (char *)mark->content);
		if (errno)
			return ;
		mark = mark->next;
		target = target->next;
	}
}

char	*redir_handler(t_commands *commands, char *str)
{
	char	*except_redir;

	except_redir = parse_redir(commands, str);
	if (!errno)
		mapping_redir(commands);
	return (except_redir);
}
