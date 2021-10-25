#include "minishell.h"

int	terminal_handler(struct termios *old_term)
{
	struct termios	new_term;

	tcgetattr(STDIN_FILENO, old_term);
	tcgetattr(STDIN_FILENO, &new_term);
	new_term.c_lflag &= ~ECHOCTL;
	new_term.c_cc[VKILL] = 0;
	new_term.c_cc[VSUSP] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &new_term);
	return (0);
}
