/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands_err.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:26:02 by mchae             #+#    #+#             */
/*   Updated: 2021/11/26 02:58:34 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	parse_mapped(t_commands *commands, char *mapped, char *mark)
{
	char	*input;

	if (*mark == '<')
	{
		free(commands->redir_in);
		commands->redir_in = ft_strdup(mark);
		if (ft_strncmp(commands->redir_in, "<", 2) == 0)
		{
			free(commands->redir_input);
			input = redir_input(mapped);
			commands->redir_input = input;
			free(mapped);
		}
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
		mapped = mapping_dollar(commands, \
			(char *)target->content, commands->old_errno);
		if ((mapped == NULL || ft_strchr(mapped, ' ')))
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

static int	check_systax(char *target)
{
	if (ft_strnstr_f(target, "<<", ft_strlen(target), check_quote))
		return (print_systax_err("<<"));
	else if (ft_strnstr_f(target, ">>", ft_strlen(target), check_quote))
		return (print_systax_err(">>"));
	else if (ft_strchr_f(target, '<', BOTH, check_quote))
		return (print_systax_err("<"));
	else if (ft_strchr_f(target, '>', BOTH, check_quote))
		return (print_systax_err(">"));
	else if (*target == '\0')
		return (print_systax_err("newline"));
	return (0);
}

static int	redir_check(char **input, char *redir, char *target)
{
	char	*tmp;

	if (ft_strncmp(redir, "<<", 2) == 0)
	{
		if (check_systax(target) != RET_ERR_INT)
		{
			tmp = redir_heredoc(target);
			*input = tmp;
			*target = 'a';
		}
	}
	else if (ft_strncmp(redir, "<", 1) == 0)
		check_systax(target);
	else if (ft_strncmp(redir, ">>", 2) == 0)
		check_systax(target);
	else if (ft_strncmp(redir, ">", 1) == 0)
		check_systax(target);
	if (errno)
		return (RET_ERR_INT);
	return (0);
}

int	check_commands_err(t_commands *commands)
{
	t_list	*mark;
	t_list	*target;

	mark = commands->redir_lst_mark;
	target = commands->redir_lst_target;
	while (mark && !errno)
	{
		if (ft_strncmp((char *)mark->content, "<<", 2) == 0)
		{
			free(commands->redir_input);
			commands->redir_input = 0;
		}
		redir_check(&commands->redir_input, (char *)mark->content, \
			(char *)target->content);
		mark = mark->next;
		target = target->next;
	}
	if (!errno)
		mapping_redir(commands);
	if (errno)
		return (RET_ERR_INT);
	return (0);
}
