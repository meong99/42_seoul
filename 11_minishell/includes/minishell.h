#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <errno.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <signal.h>
# include <string.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

# define RET_ERR_INT -1
# define RET_ERR_NULL 0
# define CHILD 0
# define PARENTS 1
# define FOR_READ 0
# define FOR_WRITE 1
# define NOT_FOUND NULL
# define ALL_CHILD 0

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
	char	*redir_in;
	char	*redir_in_target;
	char	*redir_out;
	char	*redir_out_target;
	int		index;
	int		count_pipe;
	int		**fd;
}	t_commands;

t_env		*g_env;

extern int	rl_replace_line(void);

/*
** command
*/
int			exe_export(t_commands *commands);
int			check_export_error(char *key, char *arg);
int			check_first_char(char *str);
void		print_export_env(void);
void		sorting_export(t_env *set, t_env *compare, t_env **head);

int			exe_unset(t_commands *commands);
int			check_unset_error(char *key);

void		exe_env(t_commands *commands);

void		exe_echo(t_commands *commands);

void		exe_bin(t_commands *commands);
void		check_bin_error(char *com);
char		*set_path(t_commands *commands);

void		exe_cd(t_commands *commands);

void		exe_pwd(void);

void		exe_exit(t_list *arg);

/*
** init
*/
void		init_env_var(char **envp);
void		init_commands(t_commands *commands);
t_env		*new_env_node(char *key, char *value, int *env_num);

/*
** parse
*/
t_commands	*split_pipe(char *str);
int			inside_quote(char *str, char *pointer);

/*
** redirection
*/
char		*redir_input(char *filename);
void		redir_output(char *output, char *target);
void		redir_append(char *output, char *target);
char		*redir_heredoc(char *delimiter);

/*
** set_command
*/
int			exe_commands(t_commands *commands);
void		dup_fd(t_commands *commands);

#endif
