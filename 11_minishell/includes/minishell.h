#ifndef MINISEHLL_H
# define MINISEHLL_H

# include <stdio.h>
# include <errno.h>
# include <readline/readline.h>
# include "libft.h"
# include <stdbool.h>
# include <signal.h>

# define RET_ERR_INT -1
# define RET_ERR_CHAR 0
# define C_PROCESS 0
# define FOR_READ 0
# define FOR_WRITE 1

typedef struct s_commands
{
	char	*com;
	t_list	*arg;
	t_list	*redirections;
	t_list	*filename;
	t_list	*delimiter;
	int		index;
	int		count_pipe;
}	t_commands;

typedef struct s_fd
{
	int	fd_to_c[2];
	int	fd_to_p[2];
}	t_fd;

extern int rl_replace_line();

/*
** error.c
*/

/*
** heredoc.c
*/
char		*get_hererdocs_input(t_commands *commands);

/*
** init_all.c
*/
void		init_all(t_commands *commands);

/*
** pipe.c
*/
void		make_pipe(t_fd *fd);

/*
** quotatio_mark.c
*/
int			inside_quote(char *str, char *pointer);

/*
** run_c_process.c
*/
void		run_c_process(t_commands *commands, t_fd *fd);

/*
** run_p_process.c
*/
void		run_p_process(t_commands *commands, t_fd *fd);

/*
** split_and_parsing.c
*/
char		**split_before_char(char *str, char c);
void		split_space(char *str, t_commands *commands);
t_commands	*split_pipe(char *str);

#endif
