#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include <stdbool.h>
# include <readline/readline.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <string.h>
# define BLEN 30
int main(void)
{
	int		fd[2], pid[2];

	pipe(fd);
	for (int i = 0; i < 2; i++)
	{
		pid[i] = fork();
		if (pid[i] && i == 1)
		{
			// write(fd[1], "asd", 3);
			// close(fd[1]);
			// close(fd[0]);
			return (0);
		}
		else if (pid[i])
		{
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
			// close(fd[1]);
			char **str = malloc(sizeof(char *) * 2);
			str[0] = "/bin/cat";
			str[1] = 0;
			execve(str[0], str, NULL);
		}
	}
	// write(fd[1], "asd", 3);
	// close(fd[1]);
	// close(fd[0]);
	int status;
	wait(&status);
}
