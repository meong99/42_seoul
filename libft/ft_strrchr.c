/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 10:33:37 by mchae             #+#    #+#             */
/*   Updated: 2020/10/14 17:17:22 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *input_str, int input_char)
{
	char	*temp_input_str;
	int		input_str_len;

	input_str_len = ft_strlen(input_str);
	temp_input_str = (char*)input_str + input_str_len;
	while (*input_str && input_str_len-- + 1)
	{
		if (*temp_input_str == input_char)
			return (temp_input_str);
		temp_input_str--;
	}
	return (NULL);
}
