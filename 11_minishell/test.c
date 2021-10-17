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
	int	fd[2];

	pipe(fd);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	execve("/bin/cat", NULL, NULL);
}
