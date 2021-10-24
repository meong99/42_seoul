#include "minishell.h"

static char	*ret_input(char *start, char *end)
{
	char	*filename;
	char	*input;
	int		i;

	while (*start == ' ')
		start++;
	i = 0;
	while (start[i] && start + i <= end)
		i++;
	filename = malloc(i + 1);
	i = 0;
	while (start[i] && start + i <= end)
	{
		filename[i] = start[i];
		i++;
	}
	filename[i] = 0;
	input = redir_heredoc(filename);
	free(filename);
	return (input);
}

static char	*filename_range(char *start)
{
	char	*end;
	int		i;

	i = 0;
	while (start[i] == ' ')
		i++;
	end = start + i;
	while (start[i])
	{
		end = start + i;
		if (ft_strchr("< >", start[i]))
		{
			if (!check_quote(start, start + i, BOTH))
			{
				end--;
				break ;
			}
		}
		i++;
	}
	return (end);
}

char	*parse_heredoc(t_commands *commands, char *str)
{
	char	*start;
	char	*end;

	start = ft_strnstr_f(str, "<<", ft_strlen(str), check_quote);
	if (!ft_isalnum(start[2] && start[2] != '_'))
	{
		errno = 258;
		printf("bash: syntax error near unexpected token `%c'\n", start[2]);
		return (NULL);
	}
	end = filename_range(start + 2);
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
	commands->redir_input = ret_input(start + 2, end);
	commands->redir_in = ft_strdup("<<");
	return (ft_cut(str, start, end));
}
