#include "minishell.h"

static char	*get_input(char *start, char *end)
{
	char	*filename;
	char	*input;
	int		i;

	i = 0;
	while (*start == '<' || *start == ' ')
		start++;
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
	input = redir_input(filename);
	free(filename);
	return (input);
}

static char	*filename_range(char *start)
{
	char	*end;
	int		i;

	i = 0;
	while (start[i] == '<' || start[i] == ' ')
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

char	*parse_less(t_commands *commands, char *str)
{
	char	*start;
	char	*end;

	start = ft_strchr_f(str, '<', BOTH, check_quote);
	end = filename_range(start);
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
	commands->redir_input = get_input(start, end);
	commands->redir_in = ft_strdup("<");
	return (ft_cut(str, start, end));
}
