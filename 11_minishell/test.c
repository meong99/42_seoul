#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include <stdbool.h>
# include <readline/readline.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(void)
{
	char *str;

	str = strerror(0);
	printf("%s\n", str);
}
