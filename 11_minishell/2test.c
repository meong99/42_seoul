#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include <stdbool.h>
# include <readline/readline.h>

char	get_mark(char *str)
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

int	inside_quote(char *str, char *pointer)
{
	char	mark;
	char	*front;
	char	*back;

	if (str == NULL || pointer == NULL)
		return (false);
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

static size_t	get_arr_size(const char *s, char c, int (*f)(char *, char *))
{
	size_t	num;
	size_t	i;

	i = 0;
	num = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && (s[i] != c || f(s, &s[i]) == true))
				i++;
			num++;
		}
		else
			i++;
	}
	return (num);
}

static size_t	get_alloc_size(char const *s, char c, int (*f)(char *, char *))
{
	size_t	i;

	i = 0;
	while (s[i] && (s[i] != c || f(s, &s[i])))
		i++;
	return (i);
}

static void	*free_arr(char **double_str, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(double_str[index]);
		double_str[i++] = NULL;
	}
	free(double_str);
	double_str = NULL;
	return (NULL);
}

void	*copy_str(t_split *split, char *str, char c, int (*f)(char *, char *))
{
	char *tmp;

	tmp = str;
	while (split->arr_size--)
	{
		while (*tmp && *tmp == c)
			tmp++;
		split->alloc_size = get_alloc_size(tmp, c, f) + 1;
		split->double_str[split->index] = (char *)malloc(split->alloc_size);
		if (!split->double_str[split->index])
			return (free_arr(split->double_str, split->index));
		ft_strlcpy(split->double_str[split->index++], tmp, split->alloc_size);
		while (true)
		{
			tmp = ft_strchr(tmp, c);
			if (f(str, tmp))
				tmp++;
			else
				break ;
		}
	}
}

char	**my_split(char const *s, char c, int (*f)(char *, char *))
{
	t_split	split;

	if (!s)
		return (NULL);
	split.index = 0;
	split.arr_size = get_arr_size(s, c, f);
	split.double_str = (char **)malloc(sizeof(char *) * (split.arr_size + 1));
	if (!split.double_str)
		return (NULL);
	copy_str(&split, s, c, f);
	split.double_str[split.index] = NULL;
	return (split.double_str);
}

int main(void)
{
	char *str;
	char **spl;

	str = readline("in >");
	spl = my_split(str, ' ', inside_quote);
	while (*spl)
	{
		printf("%s\n", *spl);
		spl++;
	}
}