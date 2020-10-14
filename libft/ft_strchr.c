/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 11:09:21 by mchae             #+#    #+#             */
/*   Updated: 2020/10/14 16:45:17 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *input_str, int input_char)
{
	char *temp_input_str;

	temp_input_str = (char *)input_str;
	while (*temp_input_str)
	{
		if (*temp_input_str == input_char)
			return (temp_input_str);
		temp_input_str++;
	}
	if (input_char == '\0')
		return (temp_input_str);
	return (0);
}
