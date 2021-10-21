#include "minishell.h"

static char	*get_filename(char *start, char *end)
{
	char	*filename;
	int		i;

	i = 0;
	while (*start == '>' || *start == ' ')
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

	while (*start == '>' || *start == ' ')
		start++;
	end = ft_strchr_f(start, ' ', BOTH, check_quote);
	if (end == NULL)
		end = start + ft_strlen(start);
	else
		end--;
	return (end);
}

char	*parse_append(t_commands *commands, char *str)
{
	char	*start;
	char	*end;

	start = ft_strchr_f(str, '>', BOTH, check_quote);
	end = filename_range(start);
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
	commands->redir_out_file = get_filename(start, end);
	commands->redir_out = ft_strdup(">>");
	return (ft_cut(str, start, end));
}
