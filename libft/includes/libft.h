/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <jmorcom-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:07:22 by jmorcom-          #+#    #+#             */
/*   Updated: 2023/04/17 13:46:09 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdarg.h>
#include <sys/types.h>

typedef struct s_list		t_list;
typedef struct s_stack		t_stack;
typedef struct s_sac_a_dos	t_sac_a_dos;

typedef struct s_list{
	t_list	*next;
	int		content;
	int		index;
}t_list;

typedef struct s_stack{
	int		size;
	t_list	*head;
}t_stack;

typedef struct s_sac_a_dos{
	t_stack	*a;
	t_stack	*b;
	int		full_size;
}t_sac_a_dos;

void	ft_bzero(void *s, int n);
void	*ft_memchr(const void *s, int c, int np);
int		ft_memcmp(const void *s1, const void *s2, int n);
void	*ft_memcpy(void *dst, const void*src, int n);
void	*ft_memmove(void *dst, const void *src, int len);
void	*ft_memset(void *b, int c, int len);

int		ft_atoi(const char *str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_strchr(const char *s, int c);
int		ft_strlcat(char *dst, const char *src, int dstsize);
int		ft_strlcpy(char *dst, const char *src, int dstsize);
int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, int n);
char	*ft_strnstr(char *str, char *to_find, int len);
char	*ft_strrchr(const char *s, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

char	*ft_strdup(char *s1);
void	*ft_calloc(int count, int size);

char	*ft_substr(char const *s, unsigned int start, int len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char *s1, char *set);
char	**ft_split(char *str);
char	**ft_splitt(char const *s, char c);
int		ft_wordcount(char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_putstr(char *s);
int		ft_putchar(char c);
void	ft_putendl_fd(char *s, int fd);
int		ft_putendl(char *s);
char	*ft_itoa(int n);
char	*ft_strmapi(char *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));

#endif