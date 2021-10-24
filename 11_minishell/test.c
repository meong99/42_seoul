#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include <stdbool.h>
# include <readline/readline.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <string.h>
# include <errno.h>
# define BLEN 30

int main(void)
{
	// int		fd[2];
	// int		pid;


	// pipe(fd);
	char **str = malloc(sizeof(char *) * 3);
	str[0] = "/bin/cat";
	str[1] = ",";
	str[2] = 0;
	// pid = fork();
	// if (pid == 0)
	// {
	// 	dup2(fd[1], STDOUT_FILENO);
	// 	close(fd[1]);
	// 	execve(str[0], str, NULL);
	// }
	// int status;
	// int	tmp;
	// // write(fd[1], "asd", 3);
	// // close(fd[1]);
	// // close(fd[0]);
	// tmp = wait(&status);
	// dup2(fd[0], STDIN_FILENO);
	// printf("main\n");
	// close(fd[1]);
	execve(str[0], str, NULL);
	printf("ASd\n");
}
