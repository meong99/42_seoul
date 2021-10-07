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

int main(int ac, char **av, char **envp)
{
	char **argv;

	av = 0;
	ac = 0;
	argv = malloc(sizeof(char *) * 2);
	argv[0] = "ls";
	argv[1] = NULL;
	execve("/bin/ls", argv, envp);
	printf("%s\n", strerror(errno));
}
