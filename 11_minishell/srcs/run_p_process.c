#include "minishell.h"

void	delon(void *asd)
{
	free(asd);
}

void	run_p_process(t_commands *commands, t_fd *fd)
{
	char	*str;
	char	**split;
	int		i;
	int		*pid;
	int		wstatus;
	int		len;

	i = -1;
	len = 0;
	str = readline("minishell >");
	add_history(str);
	split = ft_split_f(str, '|', inside_quote);
	while (split[len])
		len++;
	pid = malloc(sizeof(int) * len);
	while (split[++i])
	{
		pid[i] = fork();
		if (pid[i] == -1)
		{
			printf("fork errror\n");
			exit(errno);
		}
		if (pid[i])
		{
			write(fd->fd_to_c[FOR_WRITE], split[i], ft_strlen(split[i]));
			write(fd->fd_to_c[FOR_WRITE], "\n", 1);
			if (wait(&wstatus) == -1)
			{
				printf("wait error\n");
				exit(0);
			}
			printf("parent working\n");
		}
		else
			run_c_process(commands, fd);
	}
	free(str);
	ft_free(split, 0, true);
	ft_free(commands->arg, 0, true);
	free(commands->com);
	free(commands->delimiter);
	free(commands->filename);
	free(commands->redirections);
	init_all(commands);
}
