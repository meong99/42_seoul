#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include <stdbool.h>
# include <readline/readline.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <string.h>

int main(void)
{
	int		fd[2];
	char	**str;
	int		pid;
	char	buf[10];
	str = malloc(sizeof(char *) * 2);
	str[0] = "/bin/ls";
	str[1] = NULL;
	pipe(fd);
	pid = fork();
	if (pid)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execve(str[0], str, NULL);
	}
	else
	{
		wait(&pid);
		read(fd[0], buf, 10);
		write(STDOUT_FILENO, buf, 10);
	}
}
