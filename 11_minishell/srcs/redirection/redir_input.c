#include "minishell.h"

static char	*ret_input(char *redir, char *filename)
{
	int		fd;
	char	*str;
	char	buf[10];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		errno = 1;
		return (NULL);
	}
	str = ft_strdup("");
	while (read(fd, buf, 10) != 0)
	{
		if (errno != 0)
			return (NULL);
		str = ft_strjoin_free(str, buf);
	}
	close(fd);
	return (str);
}

char	*redir_input(t_list *redir, t_list *filename)
{
	char	*input;
	char	temp;

	input = ft_strdup("");
	while (redir && filename)
	{
		temp = ret_input((char *)redir->content, (char *)filename->content);
		if (temp == NULL)
			return ((char *)filename->content);
		input = ft_strjoin_free(input, temp);
		free(temp);
		redir = redir->next;
		filename = filename->next;
	}
	return (input);
}
