#include "minishell.h"

static void	delete(void *str)
{
	free(str);
}

static void	guard_dangling(t_commands *commands, char **str)
{
	init_commands(commands);
	commands->index = 0;
	commands->pipe_num =0;
	free(commands);
	*str = 0;
}

static void	free_var(t_commands *commands, char **str)
{
	free(commands->com);
	ft_lstclear(&commands->arg, delete);
	free(commands->redir_in);
	free(commands->redir_input);
	free(commands->redir_out);
	free(commands->redir_out_file);
	free(*str);
}

static void	close_fd(int **fd, int pipe_num)
{
	int	i;

	i = -1;
	while (++i < pipe_num)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		free(fd[i]);
	}
	free(fd);
}

void	free_all(t_commands *commands, char **str, int **fd)
{
	close_fd(fd, commands->pipe_num);
	free_var(commands, str);
	guard_dangling(commands, str);
}
