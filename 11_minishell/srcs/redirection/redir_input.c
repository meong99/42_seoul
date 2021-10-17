#include "minishell.h"

static char	*ret_input(char *filename)
{
	int		fd;
	char	*str;
	char	buf[10];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	str = ft_strdup("");
	while (read(fd, buf, 10) != 0)
		str = ft_strjoin_free(str, buf);
	close(fd);
	return (str);
}

char	*redir_input(t_list *filename)
{
	char	*input;
	char	*tmp;

	input = ft_strdup("");
	while (filename)
	{
		tmp = ret_input((char *)filename->content);
		if (tmp == NULL)
		{
			free(input);
			free(tmp);
			return ((char *)filename->content);
		}
		input = ft_strjoin_free(input, tmp);
		free(tmp);
		filename = filename->next;
	}
	return (input);
}
