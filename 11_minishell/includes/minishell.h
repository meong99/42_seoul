#ifndef MINISEHLL_H
# define MINISEHLL_H

# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <readline/readline.h>
# include <stdbool.h>
# include "libft.h"

# define RET_ERR_INT -1
# define RET_ERR_CHAR 0
# define C_PROCESS 0

typedef struct	s_commands
{
	char				*com;
	char				*arg;
	char				*redirections;
	char				*filename;
	struct s_commands	*next;
}				t_commands;

extern int rl_replace_line();

#endif