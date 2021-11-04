#include "minishell.h"

static void	delete(void *str)
{
	free(str);
}

static void	guard_dangling(t_commands *commands)
{
	init_commands(commands);
	commands->index = 0;
	commands->pipe_num =0;
}

static void	free_var(t_commands *commands)
{
	free(commands->com);
	ft_lstclear(&commands->arg, delete);
	free(commands->redir_lst_mark);
	free(commands->redir_lst_target);
	free(commands->redir_in);
	free(commands->redir_input);
	free(commands->redir_out);
	free(commands->redir_out_file);
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
	int	i;
	int	com_num;

	close_fd(fd, commands->pipe_num);
	i = -1;
	com_num = commands->pipe_num;
	while (++i < com_num)
	{
		free_var(&commands[i]);
		guard_dangling(&commands[i]);
	}
	free(commands);
	free(*str);
	*str = 0;
}
