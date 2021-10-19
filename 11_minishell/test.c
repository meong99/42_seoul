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
# define BLEN 30

char	*ft_cut(char *str, char *start, char *end)
{
	int		len;
	char	*result;
	int		i;

	if (!str | !start | !end)
		return (NULL);
	if (start < str || end > str + ft_strlen(str))
		return (NULL);
	if (end < start || *end == '\0')
		return (NULL);
	len = start - str;
	len += ft_strlen(end + 1);
	result = malloc(len + 1);
	i = 0;
	while (*str)
	{
		if (!(str >= start && str <= end))
			result[i++] = *str;
		str++;
	}
	result[i] = 0;
	return (result);
}

int main(void)
{
	// int		fd[2];
	// int		pid;


	// pipe(fd);
	// char **str = malloc(sizeof(char *) * 2);
	// str[0] = "/bin/cat";
	// str[1] = 0;
	// pid = fork();
	// if (pid == 0)
	// {
	// 	dup2(fd[1], STDOUT_FILENO);
	// 	close(fd[1]);
	// 	execve(str[0], str, NULL);
	// }
	// int status;
	// int	tmp;
	// // write(fd[1], "asd", 3);
	// // close(fd[1]);
	// // close(fd[0]);
	// tmp = wait(&status);
	// dup2(fd[0], STDIN_FILENO);
	// printf("main\n");
	// close(fd[1]);
	// execve(str[0], str, NULL);
	char	*str;
	char	*tmp;

	str = ft_strdup("asd");
	tmp = ft_cut(str, str + 1, str + 3);
	printf("%s\n", tmp);
	system("leaks a.out");
}
