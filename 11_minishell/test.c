#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include <stdbool.h>
# include <readline/readline.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <string.h>
# include <errno.h>
#include <termios.h>

int main(void)
{
	char str[4];

	str[0] = '1';
	str[1] = -1;
	str[2] = '2';
	str[3] = 0;
	write(STDIN_FILENO, str, 4);
	read(STDIN_FILENO, str, 4);
	printf("%s\n", str);
}
