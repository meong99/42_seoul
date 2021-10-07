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
	char **argv;

	argv = malloc(sizeof(char *) * 2);
	argv[0] = "-q";
	argv[0] = NULL;
	execve("/bin/ls", argv, NULL);
}
