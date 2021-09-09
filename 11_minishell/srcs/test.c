#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <termios.h>
#include <term.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../includes/libft.h"
#include <errno.h>
#include <fcntl.h>

extern int rl_replace_line();

void	sigg(int signo)
{
	write(1, "\b\b", 2);
	write(1, "  ", 2);
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	signo = 0;
}

void	quit(int signo)
{
	signo = 0;
	exit(0);
}

int	main(void)
{
	char	*str;
	int		fd;
	struct termios	term;

	signal(SIGINT, sigg);
	signal(SIGQUIT, quit);
	printf("slot = %d\n", ttyslot());
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("fd error\n");
		exit(errno);
	}
	if ((fd = tcgetattr(0, &term)) == -1)
	{
		printf("termios error, fd = %d\n", fd);
		exit(errno);
	}
	term.c_lflag &= (~ECHOCTL);
	tcsetattr(0, TCSANOW, &term);
	while (1)
	{
		str = readline("minishell > ");
		add_history(str);
		if (strncmp(str, "exit", 5) == 0)
			exit(0);
		else if (strncmp("pp", str, 3) == 0)
			printf("ok\n");
	}
	return (0);
}
