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
		free(spl_pipe[i]);
		free(except_redir);
	}
	free(spl_pipe);
}

static void	makepipe(t_commands *commands)
{
	int		**fd;
	fd = malloc(sizeof(int *) * commands->pipe_num);
	ft_protect(fd);
	for (int i = 0; i < commands->pipe_num; i++)
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
	char		*mapped_str;

	mapped_str = mapping_dollar(str);
	errno = 0;
	spl_pipe = ft_split_f(mapped_str, '|', BOTH, check_quote);
	ft_protect(spl_pipe);
	free(mapped_str);
	commands = parse_pipe(spl_pipe);
	init_commands(commands);
	makepipe(commands);
	parse_commands(commands, spl_pipe);
	return (commands);
}
