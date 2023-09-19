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

//int	g_status;					//* Exit status of the most-recently-executed command

enum	e_builtins{
	ECHO,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT
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
    FD
};

enum	e_tokken_type{
	COMMAND,
	BUILTINS,
	ARGUMENT,
	REDIRECTION
};

enum e_redirections{
	LEFT,
	RIGHT,
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

typedef struct s_list_tokken
{
	enum e_tokken_type		type;
	enum e_builtins			builtin_id;
	enum e_redirections		redir_id;
	char					*cmd;
	char					*arg;
	char					**args;
	int						output;
	int						input;
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
    int                 fd;
	int					i;
	int					j;
	char				*key;
	char				*input;
	char				*value;
	char				*split;
	char				**builtins;
	char				**envp;
	t_list_pre			*p_head;
	t_list_tokken		*t_head;
}	t_parsing;


// PARSING
void			parseur(t_parsing *bag);
void			expand(t_parsing *sac);
void			pre_tokken(t_parsing *sac);
void			tokkenizer(t_parsing *sac);

// EXPAND
int				check_env(t_parsing *sac);
int				check_sep(char c);
char			*ft_trim(char const *str, int size_to_trim);
char			*replace_key(t_parsing *sac, int key_size);

// PRETOKKEN
int				pre_check_char(char const *c);
int				id_pretokken(t_parsing *sac);
void			split_pretokken(t_parsing *sac, int flag);
char			*tiny_split(t_parsing *sac);

// TOKKEN
void			check_builtins(t_list_pre *current, t_parsing *sac);
void			check_redirections(t_list_pre *current, t_parsing *sac);
void			check_arguments(t_list_pre *current, t_parsing *sac);
int				allocate_args(t_list_tokken *node);
void			fill_args(t_parsing *bag);
void			clean_single_quote(t_parsing *bag);
void			clean_double_quote(t_parsing *bag);


// UTILS_PARSING
int				ft_strcmp(char const *str, char const *model, int size);
bool			state_quote(t_parsing *sac, char c);
t_list_env		*lst_env_new(char *key, char *value);
void			pre_tokken_size(t_parsing *sac);
char			*get_env(const char *key, char **envp);
void			clean_lst(t_list_tokken *head);

// UTILS_LST
t_list_pre		*ft_pre_lstadd_back(t_list_pre **lst, t_list_pre *new);
t_list_pre		*ft_pre_lstlast(t_list_pre *lst);
t_list_pre		*ft_pre_lstnew(char *pre_tokken);

// UTILS_LST_TOKKEN
int				ft_t_arglstsize(t_list_tokken *lst);
t_list_tokken	*ft_t_lstnew(void);
t_list_tokken	*ft_t_lstlast(t_list_tokken *lst);
t_list_tokken	*ft_lstadd_back_token(t_parsing *sac, t_list_tokken *new);

// INIT
t_parsing		*init_parseur(t_parsing *bag, char **envp, int flag);
void			init_builtins(t_parsing *sac);
void			init_cmds(t_parsing *sac);

// Error
int				ft_error(int ERRNUMBER, t_parsing *sac);

#endif
