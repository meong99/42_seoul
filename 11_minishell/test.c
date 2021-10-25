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

# define BLEN 30

static int	mark_intact(char *str, char mark)
{
	int	i;

	i = 0;
	while (str[++i])
	{
		if (str[i] == mark)
		{
			*str = -1;
			str[i] = -1;
			break ;
		}
	}
	return (i);
}

static char	*ret_newstr(char *str)
{
	int		i;
	int		len;
	char	*newstr;

	i = -1;
	len = 0;
	while (str[++i])
	{
		if (str[i] != -1)
			len++;
	}
	newstr = malloc(len + 1);
	i = 0;
	while (*str)
	{
		if (*str != -1)
			newstr[i] = *str;
		i++;
		str++;
	}
	newstr[i] = 0;
	return (newstr);
}

char	*remove_quote(char *str)
{
	int		i;
	char	*newstr;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			i += mark_intact(str + i, str[i]);
	}
	newstr = ret_newstr(str);
	free(str);
	return (newstr);
}

int main(void)
{
	// // int		fd[2];
	// // int		pid;


	// // pipe(fd);
	// char **str = malloc(sizeof(char *) * 2);
	// str[0] = "/bin/LS";
	// // str[1] = ",";
	// str[1] = 0;
	// // str[2] = 0;
	// // pid = fork();
	// // if (pid == 0)
	// // {
	// // 	dup2(fd[1], STDOUT_FILENO);
	// // 	close(fd[1]);
	// // 	execve(str[0], str, NULL);
	// // }
	// // int status;
	// // int	tmp;
	// // // write(fd[1], "asd", 3);
	// // // close(fd[1]);
	// // // close(fd[0]);
	// // tmp = wait(&status);
	// // dup2(fd[0], STDIN_FILENO);
	// // printf("main\n");
	// // close(fd[1]);
	// execve(str[0], str, NULL);
	// printf("ASd\n");
}
