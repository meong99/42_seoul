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
struct termios	term;

void	sigg(int signo)
{
	printf("\n");
	rl_on_new_line();
	rl_replace_line("asd", 0);
	rl_redisplay();
	signo = 0;
}

void	quit(int signo)
{
	signo = 0;
	exit(0);
}

void	ft_echo(char *str, int option)
{
	if (option)
		printf("%s", str + 5);
	else
		printf("%s\n", str + 5);
}

// void	ft_cd(char *path)
// {
	
// }

int	main(void)
{
	char	*str;

	signal(SIGINT, sigg);
	signal(SIGQUIT, quit);
	if (tcgetattr(0, &term) == -1)
	{
		printf("termios error\n");
		exit(errno);
	}
	term.c_lflag &= (~ECHOCTL);
	tcsetattr(0, TCSANOW, &term);
	while (1)
	{
		str = readline("minishell > ");
		add_history(str);
		if (str == 0)
		{
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
			printf("exit\n");
			exit(0);
		}
		else if (strncmp("pp", str, 3) == 0)
			printf("ok\n");
		else if (strncmp(">>", str, 2) == 0)
		{
			int fd;
			fd = open("text.txt", O_RDWR | O_APPEND);
			char *str = "fdsadf";
			write(fd, str, 6);
			close(fd);
		}
		else if (strncmp(">", str, 1) == 0)
		{
			int fd;
			fd = open("text.txt", O_RDWR | O_TRUNC);
			char *str = "fdsadf";
			write(fd, str, 6);
			close(fd);
		}
		else if (strncmp("echo ", str, 5) == 0)
			ft_echo(str, 0);
		else// if (strncmp("ls", str, 2) == 0)
		{
			char *asd[4] = {"echo", "-n", "asd", NULL};

			execve("/bin/echo", asd, NULL);
			printf("errno = %d\n", errno);
		}
		free(str);
	}
	return (0);
}
