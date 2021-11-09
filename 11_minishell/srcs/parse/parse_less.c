/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_less.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:46:39 by mchae             #+#    #+#             */
/*   Updated: 2021/11/09 20:25:11 by mchae            ###   ########.fr       */
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

static char	*get_input(char *start, char *end)
{
	char	*filename;
	int		i;

	i = 0;
	while (*start == ' ')
		start++;
	while (start[i] && start + i <= end)
		i++;
	filename = malloc(i + 1);
	ft_protect(filename);
	i = 0;
	while (start[i] && start + i <= end)
	{
		filename[i] = start[i];
		i++;
	}
	filename[i] = 0;
	if (check_systax(filename) == RET_ERR_INT)
	{
		free(filename);
		filename = 0;
	}
	else
		filename = remove_quote(filename);
	return (filename);
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

char	*parse_less(t_commands *commands, char *str)
{
	char	*start;
	char	*end;

	start = ft_strchr_f(str, '<', BOTH, check_quote);
	end = filename_range(start + 1);
	ft_lstadd_back(&commands->redir_lst_mark, ft_lstnew(ft_strdup("<")));
	ft_lstadd_back(&commands->redir_lst_target, \
		ft_lstnew(get_input(start + 1, end)));
	return (end);
}
