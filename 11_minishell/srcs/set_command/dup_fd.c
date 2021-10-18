#include "minishell.h"

static void	dup_input(t_commands *commands)
{
	int		*fd;

	fd = commands->fd[commands->index];
	dup2(fd[FOR_READ], STDIN_FILENO);
	close(fd[FOR_READ]);
	close(fd[FOR_WRITE]);
}

static void	dup_output(t_commands *commands)
{
	int		*fd;

	fd = commands->fd[commands->index + 1];
	dup2(fd[FOR_WRITE], STDOUT_FILENO);
}

static void	handle_redir(t_commands *commands)
{
	int		*fd;
	char	*redir_str;

	redir_str = commands->redir_in_target;
	fd = commands->fd[commands->index];
	dup2(fd[FOR_READ], STDIN_FILENO);
	write(fd[FOR_WRITE], redir_str, ft_strlen(redir_str));
	close(fd[FOR_READ]);
	close(fd[FOR_WRITE]);
}

void	dup_fd(t_commands *commands)
{
	if (commands->redir_in)
		handle_redir(commands);
	else if (commands->index != 0)
		dup_input(commands);
	if (ft_strncmp(">", commands->redir_out, 2) == 0)
		redir_output(commands->redir_out_target);
	else if (ft_strncmp(">>", commands->redir_out, 3) == 0)
		redir_append(commands->redir_out_target);
	else if (commands->index + 1 != commands->count_pipe)
		dup_output(commands);
}
