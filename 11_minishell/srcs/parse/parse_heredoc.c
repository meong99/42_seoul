#include "minishell.h"

static char	*ret_input(char *start, char *end)
{
	char	*filename;
	char	*input;
	int		i;

	i = 0;
	while (*start == '<' || *start == ' ')
		start++;
	while (start[0] && start + i <= end)
		i++;
	filename = malloc(i + 1);
	i = 0;
	while (start[0] && start + i <= end)
	{
		filename[i] = start[i];
		i++;
	}
	filename[i] = 0;
	input = redir_heredoc(filename);
	free(filename);
	return (input);
}

static void	filename_range(char **start, char **end, char *str)
{
	*start = ft_strchr_f(str, '<', BOTH, check_quote);
	*end = ft_strchr_f(*start, ' ', BOTH, check_quote);
	if (*end == NULL)
		*end = *start + ft_strlen(*start);
	else
		(*end)--;
}

char	*parse_heredoc(t_commands *commands, char *str)
{
	char	*start;
	char	*end;

	filename_range(&start, &end, str);
	if (commands->redir_in)
	{
		free(commands->redir_in);
		commands->redir_in = NULL;
	}
	if (commands->redir_input)
	{
		free(commands->redir_input);
		commands->redir_input = NULL;
	}
	commands->redir_input = ret_input(start, end);
	commands->redir_in = ft_strdup("<<");
	return (ft_cut(str, start, end));
}
