/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:47:04 by mchae             #+#    #+#             */
/*   Updated: 2021/11/08 23:47:04 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*redir_heredoc(char *delimiter)
{
	char			*str;
	char			*result;

	result = ft_strdup("");
	ft_protect(result);
	while (true)
	{
		str = readline("> ");
		if (str == NULL)
			break ;
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
