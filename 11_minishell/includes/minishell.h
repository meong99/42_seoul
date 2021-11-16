/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:55:57 by mchae             #+#    #+#             */
/*   Updated: 2021/11/16 20:42:38 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <signal.h>
# include <string.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"
# include <termios.h>

# define RET_ERR_INT -1
# define RET_ERR_NULL 0
# define CHILD 0
# define PARENTS 1
# define FOR_READ 0
# define FOR_WRITE 1
# define NOT_FOUND NULL
# define ALL_CHILD 0
# define NO_REDIR 0
# define GREATER 1
# define APPEND 2
# define HEREDOC 3
# define LESS 4
# define BOTH 0
# define SINGLE_QUOTE 1
# define DOUBLE_QUOTE 2

typedef struct s_env
{
	char			*key;
	char			*value;
	int				*env_num;
	struct s_env	*next;
}	t_env;

typedef struct s_commands
{
	char			*com;
	t_list			*arg;
	t_list			*redir_lst_mark;
	t_list			*redir_lst_target;
	t_env			*env;
	struct termios	oldterm;
	char			*redir_in;
	char			*redir_input;
	char			*redir_out;
	char			*redir_out_file;
	int				sig_handle;
	int				old_errno;
	int				index;
	int				command_num;
	int				**fd;
}	t_commands;

t_commands	*g_commands;

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
void		check_bin_error(char *com, char *path);
char		*set_path(t_commands *commands);
void		exe_cd(t_commands *commands);
void		exe_pwd(void);
void		exe_exit(t_list *arg);

/*
** init
*/
t_env		*init_env_var(char **envp);
void		init_commands(t_commands *commands, t_env *env);
t_env		*new_env_node(char *key, char *value, int *env_num);

/*
** parse
*/
int			check_quote(char *str, char *pointer, int option);
char		*mapping_dollar(char *str, int old_errno);
void		parsing_handler(char *str, int old_errno, t_env *env);
void		parse_pipe(char **spl);
void		parse_space(t_commands *commands, char *str);
char		*redir_handler(t_commands *commands, char *str);
char		*parse_less(t_commands *commands, char *str);
char		*parse_heredoc(t_commands *commands, char *str);
char		*parse_greater(t_commands *commands, char *str);
char		*parse_append(t_commands *commands, char *str);
char		*remove_quote(char *str);
void		make_file(char *filename, t_commands *commands);
/*
** redirection
*/
char		*redir_input(char *filename);
void		redir_output(char *target);
void		redir_append(char *target);
char		*redir_heredoc(char *delimiter);

/*
** set_command
*/
int			set_commands(void);
void		dup_fd(t_commands *commands);
void		run_commands(t_commands *commands);
int			is_nonbuilt(char *com);

/*
** free
*/
void		free_all(char **str, int **fd);

/*
** signal
*/
void		sig_handler(int signal);

/*
** terminal
*/
int			terminal_handler(struct termios *oldterm);
int			put_sigint(void);
int			ignore_sigint(void);

/*
** error
*/
int			print_systax_err(char *token);
void		ft_protect(void *arg);
void		put_err(char *source_err, int use_exit);
int			closed_quote(char *str);
int			check_str_err(char *str);
char		*join_errmsg(char *str1, char *str2, char *str3, char *str4);

#endif
