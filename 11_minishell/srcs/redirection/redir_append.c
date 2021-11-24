/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:47:02 by mchae             #+#    #+#             */
/*   Updated: 2021/11/24 20:05:18 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_append(char *filename)
{
	int		fd;

	fd = open(filename, O_WRONLY | O_APPEND, 0644);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}
