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
	av = malloc(sizeof(char *) * 2);
	av[0] = NULL;
	av[1] = NULL;
	execve(NULL, av, NULL);
	printf("%s\n", strerror(errno));
}
