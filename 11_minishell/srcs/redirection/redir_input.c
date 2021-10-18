#include "minishell.h"

static char	*read_file(int fd)
{
	char	*str;
	int		read_len;
	char	buf[10];

	str = ft_strdup("");
	while (1)
	{
		read_len = read(fd, buf, 10);
		if (read_len == 0)
			break ;
		else if (read_len == -1)
			return (NULL);
		buf[read_len] = 0;
		str = ft_strjoin_free(str, buf);
	}
	return (str);
}

static char	*ret_input(char *filename)
{
	int		fd;
	char	*str;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		//
		printf("bash: %s: No such file or directory\n", filename);
		return (NULL);
	}
	read_file(fd);
	close(fd);
	return (str);
}

char	*redir_input(char *filename)
{
	char	*input;

	input = ret_input(filename);
	return (input);
}
