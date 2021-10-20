#include "minishell.h"

t_commands	*parsing_handler(char *str)
{
	t_commands	*commands;
	char		**spl_pipe;
	char		*except_redir;
	int			i;

	spl_pipe = ft_split_f(str, '|', BOTH, check_quote);
	commands = parse_pipe(spl_pipe);
	init_commands(commands);
	i = -1;
	while (spl_pipe[++i])
	{
		except_redir = parse_redir(&commands[i], spl_pipe[i]);
		parse_space(&commands[i], except_redir);
		free(spl_pipe[i]);
		free(except_redir);
	}
	free(spl_pipe);
	mapping_dollar(commands);
	return (commands);
}
