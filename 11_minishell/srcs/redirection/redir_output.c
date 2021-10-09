#include "minishell.h"

void	redir_output(char *output, t_list *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT);
	write(fd, output, ft_strlen(output));
}
