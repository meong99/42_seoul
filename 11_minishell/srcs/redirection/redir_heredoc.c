/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:47:04 by mchae             #+#    #+#             */
/*   Updated: 2021/11/24 04:27:30 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_sig(int fd, char **result)
{
	free(*result);
	*result = 0;
	dup2(fd, STDIN_FILENO);
}

static char	*loop_heredoc(char *delimiter)
{
	char	*str;
	char	*result;

	result = ft_strdup("");
	ft_protect(result);
	while (true)
	{
		g_commands->sig_handle = SIG_HEREDOC;
		str = readline("> ");
		if (str == NULL)
		{
			if (g_commands->sig_handle == SIG_HEREDOC)
				ft_putstr_fd("\x1b[1A\033[2C", STDOUT_FILENO);
			break ;
		}
		if (*str && ft_strncmp(str, delimiter, ft_strlen(str)) == 0)
			break ;
		result = ft_strjoin_free(result, str);
		ft_protect(result);
		result = ft_strjoin_free(result, "\n");
		ft_protect(result);
		free(str);
	}
	free(str);
	return (result);
}

char	*redir_heredoc(char *delimiter)
{
	char	*result;
	int		fd;

	fd = dup(STDIN_FILENO);
	result = loop_heredoc(delimiter);
	if (g_commands->sig_handle == AFTER_SIG_HEREDOC)
		handle_sig(fd, &result);
	else if (!*result)
		g_commands->sig_handle = AFTER_SIG_HEREDOC;
	else
		g_commands->sig_handle = SIG_USUAL;
	close(fd);
	return (result);
}
