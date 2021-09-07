#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <termios.h>
#include <term.h>

int	main(void)
{
	char *str;

	while (1)
	{
		str = readline("minishell > ");
		add_history(str);
		printf("%s\n", str);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	return (0);
}
