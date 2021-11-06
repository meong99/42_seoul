#include "minishell.h"

static void	delete(void *str)
{
	free(str);
}

static void	guard_dangling(t_commands *commands)
{
	init_commands(commands, NULL);
	commands->index = 0;
	commands->command_num =0;
}

static void	free_var(t_commands *commands)
{
	free(commands->com);
	ft_lstclear(&commands->arg, delete);
	ft_lstclear(&commands->redir_lst_mark, delete);
	ft_lstclear(&commands->redir_lst_target, delete);
	free(commands->redir_in);
	free(commands->redir_input);
	free(commands->redir_out);
	free(commands->redir_out_file);
}

static void	close_fd(int **fd, int pipe_num)
{
	int	i;

	i = 0;
	free(fd[i]);
	while (++i < pipe_num)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		free(fd[i]);
	}
	free(fd);
}

void	free_all(char **str, int **fd)
{
	int	i;
	int	com_num;

	close_fd(fd, g_commands->command_num);
	i = -1;
	com_num = g_commands->command_num;
	while (++i < com_num)
	{
		free_var(&g_commands[i]);
		guard_dangling(&g_commands[i]);
	}
	free(g_commands);
	g_commands = 0;
	free(*str);
	*str = 0;
}
