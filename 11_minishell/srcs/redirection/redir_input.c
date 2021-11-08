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
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(filename, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
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
