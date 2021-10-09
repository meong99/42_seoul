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
	av = malloc(sizeof(char *) * 5);
	av[0] = "/bin/cp";
	av[1] = "-r";
	av[2] = "asd";
	av[3] = "srcs";
	av[4] = NULL;
	execve("/bin/cp", av, NULL);
}
