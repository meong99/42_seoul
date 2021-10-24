#include "minishell.h"

static char	*get_filename(char *start, char *end)
{
	char	*filename;
	int		i;

	i = 0;
	while (*start == ' ')
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
	return (filename);
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

char	*parse_greater(t_commands *commands, char *str)
{
	char	*start;
	char	*end;

	start = ft_strchr_f(str, '>', BOTH, check_quote);
	if (!ft_isalnum(start[1] && start[1] != '_'))
	{
		errno = 258;
		printf("bash: syntax error near unexpected token `%c'\n", start[1]);
		return (NULL);
	}
	end = filename_range(start + 1);
	if (commands->redir_out)
	{
		free(commands->redir_out);
		commands->redir_out = NULL;
	}
	if (commands->redir_out_file)
	{
		free(commands->redir_out_file);
		commands->redir_out_file = NULL;
	}
	commands->redir_out_file = get_filename(start + 1, end);
	commands->redir_out = ft_strdup(">");
	return (ft_cut(str, start, end));
}
