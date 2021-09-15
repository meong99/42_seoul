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

typedef struct s_commands
{
	char				*com;
	t_list				*arg;
	char				*redirections;
	char				*filename;
	char				*delimiter;
	struct s_commands	*next;
}	t_commands;

extern int rl_replace_line();

/*
** error.c 
*/

/*
** heredoc.c 
*/
char	*get_hererdocs_input(t_commands *commands);

/*
** init_all.c
*/
void	init_all(t_commands *commands);

/*
** pipe.c 
*/
void	make_pipe(int fd_for_c[2], int fd_for_p[2]);

/*
** quotatio_mark.c 
*/
int		inside_quote(char *str, char *pointer);

/*
** split_and_parsing.c 
*/
char	**split_and_parsing(char *str, t_commands *commands);

#endif