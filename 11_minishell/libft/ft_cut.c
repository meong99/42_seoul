/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:55:10 by mchae             #+#    #+#             */
/*   Updated: 2021/11/08 23:55:10 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_err(char *str, char *start, char *end)
{
	if (!str | !start | !end)
		return (0);
	if (start < str || end > str + ft_strlen(str))
		return (0);
	if (end < start)
		return (0);
	return (1);
}

static int	ret_len(char *str, char *start, char *end)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (!(str + i >= start && str + i <= end))
			len++;
		i++;
	}
	return (len);
}

char	*ft_cut(char *str, char *start, char *end)
{
	int		len;
	char	*result;
	int		i;

	if (check_err(str, start, end) == 0)
		return (NULL);
	len = ret_len(str, start, end);
	result = malloc(len + 1);
	i = 0;
	while (*str)
	{
		if (!(str >= start && str <= end))
			result[i++] = *str;
		str++;
	}
	result[i] = 0;
	return (result);
}
