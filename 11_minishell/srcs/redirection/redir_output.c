#include "minishell.h"

static void	overwrite(char *output, char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT);
	write(fd, output, ft_strlen(output));
	close(fd);
}

static void	append(char *output, char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND);
	write(fd, output, ft_strlen(output));
	close(fd);
}

void	redir_output(char *output, t_list *redir, t_list *filename)
{
	while (redir && filename)
	{
		if (ft_strncmp(">", (char *)redir->content, 2) == 0)
			overwrite(output, (char *)filename->content);
		else
			append(output, (char *)filename->content);
		redir = redir->next;
		filename = filename->next;
	}
}
