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
	int	fd[2];
	char	buf[10];
	pipe(fd);
	// dup2(fd[1], STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	write(fd[1], "123\n", 4);
	read(STDIN_FILENO, buf, 10);
	write(1, buf, 10);
}
