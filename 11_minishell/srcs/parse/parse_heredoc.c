/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:46:35 by mchae             #+#    #+#             */
/*   Updated: 2021/11/09 22:21:31 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static char	*ret_input(char *start, char *end)
{
	char	*delimiter;
	char	*input;
	int		i;

	while (*start == ' ')
		start++;
	i = 0;
	while (start[i] && start + i <= end)
		i++;
	delimiter = malloc(i + 1);
	ft_protect(delimiter);
	i = 0;
	while (start[i] && start + i <= end)
	{
		delimiter[i] = start[i];
		i++;
	}
	delimiter[i] = 0;
	input = NULL;
	if (check_systax(delimiter) != RET_ERR_INT)
		input = redir_heredoc(delimiter);
	free(delimiter);
	return (input);
}

static char	*filename_range(char *start)
{
	char	*end;
	int		i;
	int		check_systax;

	i = 0;
	while (start[i] == ' ')
		i++;
	end = start + i;
	check_systax = 0;
	while (start[i])
	{
		end = start + i;
		if (check_systax && ft_strchr("< >", start[i]))
		{
			if (!check_quote(start, start + i, BOTH))
			{
				end--;
				break ;
			}
		}
		else if (!ft_strchr("<>", start[i]))
			check_systax++;
		i++;
	}
	return (end);
}

char	*parse_heredoc(t_commands *commands, char *str)
{
	char	*start;
	char	*end;

	start = ft_strnstr_f(str, "<<", ft_strlen(str), check_quote);
	end = filename_range(start + 2);
	ft_lstadd_back(&commands->redir_lst_mark, ft_lstnew(ft_strdup("<<")));
	ft_lstadd_back(&commands->redir_lst_target, \
		ft_lstnew(ret_input(start + 2, end)));
	return (end);
}
