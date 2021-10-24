#include "minishell.h"

t_commands	*parsing_handler(char *str)
{
	t_commands	*commands;
	char		**spl_pipe;
	char		*except_redir;
	char		*mapped_str;
	int			i;

	mapped_str = mapping_dollar(str);
	errno = 0;
	spl_pipe = ft_split_f(mapped_str, '|', BOTH, check_quote);
	free(mapped_str);
	commands = parse_pipe(spl_pipe);
	init_commands(commands);
	i = -1;
	while (spl_pipe[++i])
	{
		if (!errno)
			except_redir = parse_redir(&commands[i], spl_pipe[i]);
		if (!errno)
			parse_space(&commands[i], except_redir);
		free(spl_pipe[i]);
		free(except_redir);
	}
	free(spl_pipe);
	return (commands);
}
