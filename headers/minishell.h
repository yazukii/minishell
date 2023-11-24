/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:12:42 by yidouiss          #+#    #+#             */
/*   Updated: 2023/08/23 16:43:44 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include "libft.h"
# include "get_next_line.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/ioctl.h>

# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"

# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"
# define PATH  "/Users/yani/Library/Python/3.9/bin:/opt/homebrew/bin:/opt/home\
brew/sbin:/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbi\
n:/sbin:/Library/Apple/usr/bin:/Users/yani/Library/Python/3.9/bin:/opt/homebr\
ew/bin:/opt/homebrew/sbin:/Users/yani/.spicetify:/Users/yani/.spicetifytest"
# define MAXPATHLEN 4096

# define BOOL unsigned int
# define TRUE 1
# define FALSE 0
# define ERR -1
				//* Exit status of the most-recently-executed command

enum	e_builtins{
	ECHO,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT,
	NO_BUILTIN
};

enum	e_char{
	CHAR,
	SPACESEP,
	ONECHAR,
	TWOCHAR,
	BACKSLASH
};

enum	e_errnumber{
	MEMORY,
	ENVP,
	FD,
	SIGNAL,
	FORK,
	FILE_CREATION,
	SYNTAX,
	EXECVE
};

enum	e_tokken_type{
	NO_TYPE,
	COMMAND,
	BUILTINS,
	ARGUMENT,
	REDIRECTION
};

enum e_redirections{
	NO_REDIR,
	INPUT,
	OUTPUT,
	APPEND,
	HEREDOC,
	PIPE
};

typedef struct s_list_env
{
	char				*key;
	int					k_size;
	char				*value;
	int					v_size;
	struct s_list_env	*next;
}	t_list_env;

typedef struct s_list_pre
{
	char					*pre_tokken;
	int						size;
	struct s_list_pre		*next;
}	t_list_pre;

typedef struct s_list_arg
{
	char					*arg;
	struct s_list_arg		*next;
}	t_list_arg;

typedef struct s_list_tokken
{
	enum e_builtins			builtin_id;
	char					*cmd;
	char					*heredoc;
	t_list_arg				*a_head;
	int						output;
	int						input;
	int						append;
	char					**exec;
	int						size;
	BOOL					pipe_status;
	struct s_list_tokken	*next;
}	t_list_tokken;

typedef struct s_parsing
{
	BOOL				can_exp;
	BOOL				in_double;
	BOOL				in_simple;
	BOOL				has_expanded;
	BOOL				heredoc_flag;
	BOOL				first_cmd;
	int					index;
	int					i;
	char				*input;
	char				*hook_input;
	char				*cwd;
	t_list_env			*key;
	char				**builtins;
	t_list_env			*env_head;
	t_list_pre			*p_head;
	t_list_tokken		*t_head;
}	t_parsing;

// MAIN
void			input_handling(t_parsing *bag, char **envp);

// INIT
t_parsing		*init_parseur(t_parsing *bag, char **envp, int flag);
void			init_builtins(t_parsing *sac);
void			init_envp(t_parsing *bag, char **envp);

// PARSING
int				parseur(t_parsing *bag);
void			expand(t_parsing *bag);
void			pre_tokken(t_parsing *sac, char *prompt);
void			tokkenizer(t_parsing *sac);
void			clean_end_space(t_parsing *bag);
int				ft_number_args(t_list_tokken *current);
char			**fill_exec(t_list_tokken *current, t_parsing *bag);
void			get_option(t_parsing *bag);

// Execution
void			execution(t_parsing *bag, char **envp);
void			ft_execute(t_parsing *bag, t_list_tokken *current, char **envp);
void			ft_one_cmd(t_parsing *bag, char **envp);
void			ft_multi_cmd(t_parsing *bag, char **envp);
void			prepare_fds(t_list_tokken *cmd, int *fd_pipe_read_tmp, \
				int *fd_pipe);
void			close_fds(t_list_tokken *cmd, int *fd_pipe_read_tmp, \
				int *fd_pipe);
void			ft_run_cmd(t_parsing *bag, t_list_tokken *cmd, char **envp);
void			handle_exit_status(int exit_status);
void			ft_execute_fork(t_parsing *bag, t_list_tokken *current, \
				char **envp, int *exit_status);

// EXECUTION UTILS
char			**ft_getsplitedpath(t_list_env *head);
char			*ft_getenv(t_list_env *head, char *key);
void			ft_strcpy(char *dst, const char *src);
void			ft_strcat(char *dst, const char *src);
void			ft_freesplit(char **paths);

// EXPAND
void			clean_input(t_parsing *bag);
BOOL			check_env(t_parsing *bag);

// PRETOKKEN
char			*get_pre_token(t_parsing *bag, char **str);
int				check_redir(char *str);
BOOL			is_letter(char c);
int				word_len(char *str);
char			*get_redir(char **str, t_parsing *bag);
char			*get_word(char **str, t_parsing *bag);
int				quote_len(char *str);
BOOL			is_quote(char c);
char			*get_quote(char **str, t_parsing *bag);

// TOKKEN
void			fill_tokkens_recursive(t_parsing *bag);
void			fill_cmd(t_parsing *bag);
BOOL			fill_pipe(t_parsing *bag);
void			check_builtins(t_list_tokken *current, t_parsing *bag);

// REDIR && HEREDOC
void			write_missing(char *delimiter);
BOOL			is_eof(char *input, char *delimiter);
unsigned int	endoffile(char *input, char *delimiter);
char			*get_heredoc_input(char *delimiter, t_parsing *bag);
void			get_heredoc(t_list_pre *current, t_parsing *bag);
void			cmd_redir(t_list_pre *current, t_parsing *bag);
void			r_fill_redir(t_parsing *bag);
t_list_pre		*find_redir(t_parsing *bag);
t_list_pre		*find_before_redir(t_parsing *bag);
void			refactor_redir(t_parsing *bag);
void			clean_redir(t_parsing *bag);

// UTILS_PARSING
int				ft_strcmp(char const *str, char const *model, int size);
BOOL			state_quote(t_parsing *sac, char c);
void			debug_token(t_parsing *bag);
void			pre_tokken_size(t_parsing *sac);
int				parseur(t_parsing *bag);
void			print_exec(t_list_tokken *test);

// UTILS_LST
void			ft_pre_lstadd_back(t_list_pre *node, t_list_pre *new, \
				t_parsing *bag);
t_list_pre		*ft_pre_lstlast(t_list_pre *lst);
t_list_pre		*ft_pre_lstnew(char *pre_tokken, t_parsing *bag);

// UTILS_LST_TOKKEN
int				ft_t_arglstsize(t_list_tokken *lst);
t_list_tokken	*ft_t_lstnew(t_parsing *bag);
t_list_tokken	*ft_t_lstlast(t_list_tokken *lst);
void			ft_lstadd_back_token(t_list_tokken *node, \
				t_list_tokken *new, t_parsing *bag);

// UTILS_LST_ARG
t_list_arg		*ft_lstadd_back_arg(t_parsing *bag, t_list_arg *new);
t_list_arg		*ft_a_lstlast(t_list_arg *lst);
t_list_arg		*ft_a_lstnew(char *str, t_parsing *bag);
void			free_p_args(t_parsing *bag);

// UTILS_LST_ENV
t_list_env		*ft_env_lstnew(t_parsing *bag, char *envstr);
char			*ft_key(char *str, t_parsing *bag);
char			*ft_value(char *str, t_parsing *bag);
t_list_env		*ft_envp_lstlast(t_list_env *lst);
void			ft_lstadd_back_envp(t_parsing *bag, t_list_env *new);
void			env_add_back(t_list_env **env, t_list_env *new);
t_list_env		*env_lstlast(t_list_env *lst);

// FREE
void			free_all(t_parsing *bag);
void			free_p(t_list_pre *head);
void			free_t(t_list_tokken *head);
void			free_a(t_list_arg *head);
void			free_env(t_parsing *bag);

// Error
void			ft_error(int ERRNUMBER, t_parsing *bag);

// Builtins
int				ft_execute_builtin(t_list_tokken *current, t_parsing *bag);
int				ft_cd(t_list_tokken *current, char *cwd);
int				ft_echo(t_list_tokken *current);
int				ft_pwd(t_list_tokken *current, t_parsing *bag);
int				ft_env(t_parsing *bag);
int				ft_export(t_list_tokken *current, t_parsing *bag);
int				ft_unset(t_parsing *bag, t_list_tokken *current);

// Signals
void			handle_signal(void);

extern volatile sig_atomic_t	g_status;

#endif
