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
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
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

//int	g_status;					//* Exit status of the most-recently-executed command


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

typedef struct s_list_env
{
	char				*key;
	char				*value;
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
	int 					output;
	int 					input;
	int 					append;
	struct s_list_arg		*next;
}	t_list_arg;

typedef struct s_list_tokken
{
	enum e_builtins			builtin_id;
	char					*cmd;
	struct s_list_arg		*a_head;
	bool					pipe_status;
	struct s_list_tokken	*next;
}	t_list_tokken;

typedef struct s_parsing
{
	bool				can_exp;
	bool				in_double;
	bool				in_simple;
	bool				pipe_flag;
	int					index;
	int					value_size;
	int					key_size;
	int					split_index;
	int					i;
	int					j;
    char                *heredoc;
	char				*key;
	char				*input;
	char				*value;
	char				*split;
	char				**builtins;
	char 				*cwd;
	t_list_env			*env_head;
	t_list_pre			*p_head;
	t_list_tokken		*t_head;
}	t_parsing;


// PARSING
int			    parseur(t_parsing *bag);
int 			expand(t_parsing *sac);
void			pre_tokken(t_parsing *sac);
void			tokkenizer(t_parsing *sac);

// EXPAND
int				check_env(t_parsing *sac);
int				check_sep(char c);
char			*ft_trim(char const *str, int size_to_trim, t_parsing *bag);
char			*replace_key(t_parsing *sac, int key_size);

// PRETOKKEN
int				pre_check_char(char const *c);
int				id_pretokken(t_parsing *sac);
void			split_pretokken(t_parsing *sac, int flag);
char			*tiny_split(t_parsing *sac);

// TOKKEN
void			check_builtins(t_list_pre *current, t_parsing *sac);
int				check_redirections(t_list_pre *current, t_parsing *bag);
void			fill_tokken(t_parsing *bag);
void 			fill_cmd(t_parsing *bag, t_list_pre *tmp, enum e_redirections redir_type);
void			management_redir(t_list_arg *arg_node, enum e_redirections redir_type, t_parsing *bag);
void			create_cmd(t_parsing *bag, t_list_pre **tmp);
void			clean_single_quote(t_parsing *bag);
void			clean_double_quote(t_parsing *bag);
int				redir(t_parsing *bag, t_list_pre **tmp);

// UTILS_PARSING
int				ft_strcmp(char const *str, char const *model, int size);
bool			state_quote(t_parsing *sac, char c);
t_list_env		*lst_env_new(char *key, char *value, t_parsing *bag);
void			pre_tokken_size(t_parsing *sac);
char			*get_env(const char *key, t_list_env **envp);

// UTILS_LST
t_list_pre		*ft_pre_lstadd_back(t_list_pre **lst, t_list_pre *new);
t_list_pre		*ft_pre_lstlast(t_list_pre *lst);
t_list_pre		*ft_pre_lstnew(char *pre_tokken, t_parsing *bag);

// UTILS_LST_TOKKEN
int				ft_t_arglstsize(t_list_tokken *lst);
t_list_tokken	*ft_t_lstnew(t_parsing *bag);
t_list_tokken	*ft_t_lstlast(t_list_tokken *lst);
t_list_tokken	*ft_lstadd_back_token(t_parsing *sac, t_list_tokken *new);

// UTILS_LST_ARG
t_list_arg		*ft_lstadd_back_arg(t_parsing *bag, t_list_arg *new);
t_list_arg		*ft_a_lstlast(t_list_arg *lst);
t_list_arg		*ft_a_lstnew(t_parsing *bag);


// INIT
t_parsing		*init_parseur(t_parsing *bag, char **envp, int flag);
void			init_builtins(t_parsing *sac);
void			init_envp(t_parsing *bag, char **envp);

// UTILS_LST_ENV
t_list_env 		*ft_env_lstnew(t_parsing *bag, char *envstr);
char			*ft_key(char *str, t_parsing *bag);
char			*ft_value(char *str, t_parsing *bag);
t_list_env		*ft_env_lstlast(t_list_env *lst);
void			ft_lstadd_back_envp(t_parsing *bag, t_list_env *new);

// FREE
void			free_all(t_parsing *bag);
void			free_p(t_list_pre *head);
void			free_t(t_list_tokken *head);
void			free_a(t_list_arg *head);
void			free_env(t_parsing *bag);

// Error
int				ft_error(int ERRNUMBER, t_parsing *sac);

#endif
