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
	char	**str;
	int		pid;

	printf("1=%d\n", errno);
	pid = fork();
	printf("2=%d\n", errno);
	if (pid == 0)
	{
		str = malloc(sizeof(char *) * 3);
		str[0] = "/bin/ls";
		str[1] = "asddasdasad";
		str[2] = NULL;
		printf("3=%d\n", errno);
		execve(str[0], str, NULL);
		printf("4=%d\n", errno);
		return (0);
	}
	wait(&pid);
	if (0 == (pid & 0xff))
		printf("정상 = %d\n", pid >> 8);
	else
		printf("비정상 = %d\n", pid);
	printf("5=%d\n", errno);
}
