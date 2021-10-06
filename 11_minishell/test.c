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
	t_env *env;

	env = malloc(sizeof(t_env) * 10);
	printf("%zu\n", sizeof(env));
}
