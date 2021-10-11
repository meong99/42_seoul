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

int main(void)
{
	char **av;
	int	fd[2],fd_2[2], fd_3[2];

	pipe(fd);
	pipe(fd_2);
	pipe(fd_3);
	dup2(fd[0], STDIN_FILENO);
	av = malloc(sizeof(char *) * 2);
	av[0] = NULL;
	av[1] = NULL;
	close(fd[0]);
	write(fd[1], "asd", 3);
	close(fd[1]);
	execve("asd", av, NULL);
}
