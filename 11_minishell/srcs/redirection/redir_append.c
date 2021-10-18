#include "minishell.h"

void	redir_append(char *output, char *target)
{
	int		fd;

	fd = open(target, O_WRONLY | O_CREAT | O_APPEND);
	write(fd, output, ft_strlen(output));
	close(fd);
}
