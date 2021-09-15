#include "minishell.h"

static char	get_mark(char *str)
{
	while (*str)
	{
		if (*str == '\'' || *str == '\"')
			return (*str);
		str++;
	}
	return (RET_ERR_INT);
}

int			inside_quote(char *str, char *pointer)
{
	char	mark;
	char	*front;
	char	*back;

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
