#include "minishell.h"

static void	dup_input(t_commands *commands)
{
	int		*fd;

	fd = commands->fd[commands->index];
	dup2(fd[FOR_READ], STDIN_FILENO);
	close(fd[FOR_READ]);
}

static void	dup_output(t_commands *commands)
{
	int		*fd;

	fd = commands->fd[commands->index + 1];
	dup2(fd[FOR_WRITE], STDOUT_FILENO);
}

static void	handle_redir(t_commands *commands)
{
	char	*str;
	int		*fd;

	fd = commands->fd[commands->index];
	str = redir_input(commands->redir_in, commands->filename_in);
	dup_input(commands);
	write(fd[FOR_WRITE], str, ft_strlen(str));
	close(fd[FOR_WRITE]);
}

void	dup_fd(t_commands *commands)
{
	if (commands->redir_in)
		handle_redir(commands);
	else if (commands->index != 0)
		dup_input(commands);
	if (commands->index + 1 != commands->count_pipe)
		dup_output(commands);
}
