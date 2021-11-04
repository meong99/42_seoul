#include "minishell.h"

static void	parse_commands(t_commands *commands, char **spl_pipe)
{
	int		i;
	char	*except_redir;

	i = -1;
	while (spl_pipe[++i])
	{
		if (!errno)
			except_redir = redir_handler(&commands[i], spl_pipe[i]);
		if (!errno)
			parse_space(&commands[i], except_redir);
		free(except_redir);
		if (errno)
			break ;
	}
	i = -1;
	while (spl_pipe[++i])
		free(spl_pipe[i]);
	free(spl_pipe);
}

static void	makepipe(t_commands *commands)
{
	int	**fd;
	int	i;

	fd = malloc(sizeof(int *) * commands->pipe_num);
	ft_protect(fd);
	i = -1;
	while (++i < commands->pipe_num)
	{
		fd[i] = malloc(sizeof(int) * 2);
		ft_protect(fd[i]);
		pipe(fd[i]);
		commands[i].fd = fd;
	}
}

t_commands	*parsing_handler(char *str)
{
	t_commands	*commands;
	char		**spl_pipe;
	int			i;

	i = -1;
	errno = 0;
	spl_pipe = ft_split_f(str, '|', BOTH, check_quote);
	ft_protect(spl_pipe);
	commands = parse_pipe(spl_pipe);
	while (++i < commands->pipe_num)
		init_commands(&commands[i]);
	makepipe(commands);
	parse_commands(commands, spl_pipe);
	return (commands);
}
