#include "minishell.h"

static char	get_mark(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			if (i == 0 || str[i - 1] == '\\')	
				continue ;
			return (str[i]);
		}
	}
	return (-1);
}

int			inside_quote(char *str, char *pointer)
{
	char	mark;
	char	*front;
	char	*back;

	if (str == NULL || pointer == NULL)
	{
		printf("Can't using NULL pointer in inside_quote()");
		exit(0);
	}
	front = str;
	back = str;
	while (front && back)
	{
		mark = get_mark(front);
		if (mark == -1)
			return (false);
		front = ft_strchr(front, mark);
		back = ft_strchr(front + 1, mark);
		if (front && back)
		{
			if (front < pointer && pointer < back)
				return (true);
		}
		front = back + 1;
	}
	return (false);
}