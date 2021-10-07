#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <errno.h>
# include <readline/readline.h>
# include "libft.h"
# include <stdbool.h>
# include <signal.h>
# include <string.h>

# define RET_ERR_INT -1
# define RET_ERR_NULL 0
# define C_PROCESS 0
# define FOR_READ 0
# define FOR_WRITE 1
# define NOT_FOUND NULL

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
	int				*env_num;
}	t_env;

typedef struct s_commands
{
	char	*com;
	t_list	*arg;
	t_list	*redirections;
	t_list	*filename;
	t_list	*delimiter;
	int		index;
	int		count_pipe;
	int		**fd;
}	t_commands;

t_env		*g_env;

extern int	rl_replace_line(void);

/*
** init.c
*/
void		init_env_var(char **envp);
void		init_commands(t_commands *commands);
t_env		*new_env_node(char *key, char *value, int *env_num);

/*
** pipe.c
*/
int			**make_pipe(t_commands *commands);

/*
** split_and_parsing.c
*/
char		**split_before_char(char *str, char c);
void		split_space(char *str, t_commands *commands);
t_commands	*split_pipe(char *str);

/*
** export
*/
int			exe_export(t_commands *commands);
int			check_export_error(char *key, char *arg);
int			check_first_char(char *str);
void		print_export_env(void);
void		sorting_export(t_env *set, t_env *compare, t_env **head);

/*
** unset
*/
int			exe_unset(t_commands *commands);
int			check_unset_error(char *key);

/*
** env
*/
void		exe_env(t_commands *commands);

/*
** echo
*/
void		exe_echo(t_commands *commands);

/*
** bin
*/
void		exe_bin(t_commands *commands);

/*
** com*.c
*/
void		exe_cd(t_commands *commands);
void		exe_pwd(void);
void		exe_exit(t_commands *commands);

/*
** error.c
*/
void		print_err(char *com, t_list *arg_list);

/*
** exe_commands.c
*/
void		exe_commands(t_commands *commands);


/*
** quotatio_mark.c
*/
int			inside_quote(char *str, char *pointer);

/*
** run_c_process.c
*/
void		run_c_process(t_commands *commands);

/*
** run_p_process.c
*/
void		run_p_process(t_commands *commands);

/*
** heredoc.c
*/
char		*get_hererdocs_input(t_commands *commands);

#endif
