#include "minishell.h"

static void	dup_input(t_commands *commands)
{
	int		*fd;

	fd = commands->fd[commands->index];
	if (commands->index != 0)
		dup2(fd[FOR_READ], STDIN_FILENO);
	close(fd[FOR_READ]);
	close(fd[FOR_WRITE]);
}

static void	dup_output(t_commands *commands)
{
	int		*fd;

	fd = commands->fd[commands->index + 1];
	dup2(fd[FOR_WRITE], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
}

static void	handle_redir_in(t_commands *commands)
{
	int		*fd;
	char	*redir_str;

	redir_str = commands->redir_input;
	fd = commands->fd[commands->index];
	dup2(fd[FOR_READ], STDIN_FILENO);
	write(fd[FOR_WRITE], redir_str, ft_strlen(redir_str));
	close(fd[FOR_READ]);
	close(fd[FOR_WRITE]);
}

static void	handle_redir_out(t_commands *commands)
{
	if (ft_strncmp(">>", commands->redir_out, 3) == 0)
		redir_append(commands->redir_out_file);
	else
		redir_output(commands->redir_out_file);
}

void	dup_fd(t_commands *commands)
{
	if (commands->redir_input)
		handle_redir_in(commands);
	else
		dup_input(commands);
	if (commands->redir_out_file)
		handle_redir_out(commands);
	else if (commands->index + 1 != commands->pipe_num)
		dup_output(commands);
}
