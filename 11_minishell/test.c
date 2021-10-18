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
	// int		*fd;

	// fd = malloc(sizeof(int) * 2);
	// pipe(fd);
	// int	pid = fork();
	// if (pid == 0)
	// {
	// 	dup2(fd[0], STDIN_FILENO);
	// 	char buf[10];
	// 	read(STDIN_FILENO, buf, 5);
	// 	write(1, buf, 10);
	// 	return (0);
		// char **str = malloc(sizeof(char *) * 2);
		// str[0] = "/bin/ls";
		// str[1] = 0;
		// execve("/bin/ls", str, NULL);
	// }
	char **av;
	av = malloc(sizeof(char *) * 5);
	av[3] = 0;
	av[0] = "/bin/cat";
	av[1] = "b";
	av[2] = "c";
	av[3] = "a";
	execve("/bin/cat", av, NULL);
}
