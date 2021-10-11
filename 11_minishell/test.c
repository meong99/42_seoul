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
	int	**fd;

	fd = malloc(sizeof(int*) * 10);
	for (int i = 0; i < 10; i++)
	{
		fd[i] = malloc(sizeof(int) * 2);
		pipe(fd[i]);
	}
}
