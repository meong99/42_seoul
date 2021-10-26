#include "minishell.h"

static int	mark_intact(char *str, char mark)
{
	int	i;

	i = 0;
	while (str[++i])
	{
		if (str[i] == mark)
		{
			*str = -1;
			str[i] = -1;
			break ;
		}
	}
	return (i);
}

static char	*ret_newstr(char *str)
{
	int		i;
	int		len;
	char	*newstr;

	i = -1;
	len = 0;
	while (str[++i])
	{
		if (str[i] != -1)
			len++;
	}
	newstr = malloc(len + 1);
	ft_protect(newstr);
	i = -1;
	while (*str)
	{
		if (*str != -1)
			newstr[++i] = *str;
		str++;
	}
	newstr[++i] = 0;
	return (newstr);
}

char	*remove_quote(char *str)
{
	int		i;
	char	*newstr;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			i += mark_intact(str + i, str[i]);
	}
	newstr = ret_newstr(str);
	free(str);
	return (newstr);
}
