/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:12:42 by yidouiss          #+#    #+#             */
/*   Updated: 2023/07/31 12:13:35 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"
# define PATH  "/Users/yani/Library/Python/3.9/bin:/opt/homebrew/bin:/opt/homebrew/sbin:/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Apple/usr/bin:/Users/yani/Library/Python/3.9/bin:/opt/homebrew/bin:/opt/homebrew/sbin:/Users/yani/.spicetify:/Users/yani/.spicetifytest"

int	g_status;					//* Exit status of the most-recently-executed command

typedef	struct	s_args
{
	int		narg;
	char	**arg;
}	t_args;

typedef struct s_prompt
{
	t_list	*cmds;				//* Reference to s_mini
	char	**envp;				//*
	pid_t	**pid;				//* Pid of this minishell instance
}			t_prompt;

typedef struct s_mini
{
	char	**full_cmd;			//* Self explanatory
	char	*full_path;			//* 
	int		infile;				//* File descriptor to take input from
	int		outfile;			//* File descriptor to outpout to
}				t_mini;

typedef struct s_split
{
	char	**cmd;
	int		b;
	int		e;
	int		i;
	int		sw;
	int		j;
}				t_split;

int		splitargs(char *input);
int		checksquotes(char c, int i);
void	expand(char **str);
void	tilde(char **str);
int		ft_cmdnum(char const *s, char c);
int		ft_error();
char	**ft_cmdsplit(char *str, char s);
int		check_env(char* input);
int		command(t_args args);
int		parsing(char *input);
char	*pwd(int ret);
int		echo(char *input);

#endif
