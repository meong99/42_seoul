#include "minishell.h"

static char	*read_file(int fd)
{
	char	*str;
	int		read_len;
	char	buf[10];

	str = ft_strdup("");
	while (1)
	{
		read_len = read(fd, buf, 9);
		if (read_len == 0)
			break ;
		else if (read_len == -1)
			return (NULL);
		buf[read_len] = 0;
		str = ft_strjoin_free(str, buf);
		ft_protect(str);
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
		str = strerror(errno);
		write(2, "minishell: ", 11);
		write(2, filename, ft_strlen(filename));
		write(2, ": ", 2);
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
		errno = 1;
		return (NULL);
	}
	str = read_file(fd);
	close(fd);
	return (str);
}

char	*redir_input(char *filename)
{
	char	*input;

	if (filename == NULL)
		return (NULL);
	input = ret_input(filename);
	return (input);
}
