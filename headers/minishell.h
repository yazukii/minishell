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
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ioctl.h>

# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"n

# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"
# define PATH  "/Users/yani/Library/Python/3.9/bin:/opt/homebrew/bin:/opt/homebrew/sbin:/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Apple/usr/bin:/Users/yani/Library/Python/3.9/bin:/opt/homebrew/bin:/opt/homebrew/sbin:/Users/yani/.spicetify:/Users/yani/.spicetifytest"

# define bool unsigned int
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
	SYNTAX
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

typedef struct s_status
{
	int	status;
	int	child_pid;
	int quit;
}	t_status;

typedef struct s_list_env
{
	char				*key;
	int					k_size;
	char				*value;
	int 				v_size;
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
	char 					*arg;
	struct s_list_arg		*next;
}	t_list_arg;

typedef struct s_list_tokken
{
	enum e_builtins			builtin_id;
	char					*cmd;
	char					*heredoc;
	struct s_list_arg		*a_head;
	int 					output;
	int 					input;
	int 					append;
	bool					pipe_status;
	struct s_list_tokken	*next;
}	t_list_tokken;

typedef struct s_parsing
{
	bool				can_exp;
	bool				in_double;
	bool				in_simple;
	bool				has_expanded;
	bool				heredoc_flag;
	bool				first_cmd;
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
void			input_handling(t_parsing *bag);

// INIT
t_parsing		*init_parseur(t_parsing *bag, char **envp, int flag);
void			init_builtins(t_parsing *sac);
void			init_envp(t_parsing *bag, char **envp);

// PARSING
int			    parseur(t_parsing *bag);
void expand(t_parsing *bag);
void 			pre_tokken(t_parsing *sac, char *prompt);
void			tokkenizer(t_parsing *sac);
void			clean_end_space(t_parsing *bag);

// EXPAND
void 			clean_input(t_parsing *bag);
bool 			check_env(t_parsing *bag);

// PRETOKKEN
char *get_pre_token(t_parsing *bag, char **str);
int check_redir(char *str);
bool is_letter(char c);
int word_len(char *str);
char *get_redir(char **str, t_parsing *bag);
char *get_word(char **str, t_parsing *bag);
int quote_len(char *str);
bool is_quote(char c);
char *get_quote(char **str, t_parsing *bag);

// TOKKEN
void			fill_tokkens_recursive(t_parsing *bag);
void 			fill_cmd(t_parsing *bag);
bool fill_pipe(t_parsing *bag);

// REDIR && HEREDOC
void write_missing(char *delimiter);
bool is_eof(char *input, char *delimiter);
unsigned int endoffile(char *input, char *delimiter);
char *get_heredoc_input(char *delimiter, t_parsing *bag);
void get_heredoc(t_list_pre *current, t_parsing *bag);
void			cmd_redir(t_list_pre *current, t_parsing *bag);
void			r_fill_redir(t_parsing *bag);
t_list_pre		*find_redir(t_parsing *bag);
t_list_pre		*find_before_redir(t_parsing *bag);
void clean_redir(t_parsing *bag);

// UTILS_PARSING
int				ft_strcmp(char const *str, char const *model, int size);
bool			state_quote(t_parsing *sac, char c);
t_list_env		*lst_env_new(char *key, char *value, t_parsing *bag);
void			pre_tokken_size(t_parsing *sac);

// UTILS_LST
void			ft_pre_lstadd_back(t_list_pre *node, t_list_pre *new, t_parsing *bag);
t_list_pre		*ft_pre_lstlast(t_list_pre *lst);
t_list_pre		*ft_pre_lstnew(char *pre_tokken, t_parsing *bag);

// UTILS_LST_TOKKEN

int				ft_t_arglstsize(t_list_tokken *lst);
t_list_tokken	*ft_t_lstnew(t_parsing *bag);
t_list_tokken	*ft_t_lstlast(t_list_tokken *lst);
void ft_lstadd_back_token(t_list_tokken *node, t_list_tokken *new, t_parsing *bag);

// UTILS_LST_ARG
t_list_arg		*ft_lstadd_back_arg(t_parsing *bag, t_list_arg *new);
t_list_arg		*ft_a_lstlast(t_list_arg *lst);
t_list_arg		*ft_a_lstnew(char *str, t_parsing *bag);
void free_p_args(t_parsing *bag);

// UTILS_LST_ENV
t_list_env 		*ft_env_lstnew(t_parsing *bag, char *envstr);
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
void ft_error(int ERRNUMBER, t_parsing *bag);

// Execution
int 			execution(t_parsing *bag);
void			exec_cmd(t_parsing *bag);

// Builtins
void    		choose_builtin(t_parsing *bag);
int 			cd(t_parsing *bag);
void			echo(t_parsing *bag);
int				pwd(t_parsing *bag);
int				env(t_parsing *bag);
void 			export(t_parsing *bag);
void			unset(t_parsing *bag);

// Signals
void			handle_signal(t_parsing *bag);

extern t_status g_status;
#endif
