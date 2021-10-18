#include "minishell.h"

void	redir_output(char *output, char *target)
{
	int	fd;

	fd = open(target, O_WRONLY | O_CREAT);
	write(fd, output, ft_strlen(output));
	close(fd);
}
