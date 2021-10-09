#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include <stdbool.h>
# include <readline/readline.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>


typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

int main(int ac, char **av, char **envp)
{
	int	fd[2];
	char	buf[2];

	int	eof = -1;

	pipe(fd);
	int	pid = fork();
	if (pid == 0)
	{
		char **av;
		av = malloc(sizeof(char *) * 3);
		av[0] = "/usr/bin/grep";
		av[1] = "hi";
		av[2] = NULL;
		read(fd[0], buf, 2);
		write(0, buf, 2);
		write(0, &eof, 2);
		execve("/usr/bin/grep", av, NULL);
	}
	else
	{
		int a;
		write(fd[1], "hi", 2);
		wait(&a);
		printf("end\n");
	}
}
