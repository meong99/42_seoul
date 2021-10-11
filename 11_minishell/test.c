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
	int	fd;

	fd = open("asd", O_WRONLY | O_CREAT | O_APPEND);
	write(fd, "456", 3);
	close(fd);
}
