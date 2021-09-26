#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include <stdbool.h>
# include <readline/readline.h>
#include <fcntl.h>

int main(void)
{
	char str[5];
	int	fd;
	int test;

	fd = open("test", O_RDWR);
	write(fd, "asd\n", 4);
	test = lseek(fd, 0, SEEK_SET);
	read(fd, str, 4);
	printf("%s, %d\n", str, test);
}
