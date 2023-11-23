#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
typedef struct s_list_pre
{
	char				*key;
	int					k_size;
	char				*value;
	int 				v_size;
	struct s_list_pre	*next;
}	t_list_pre;
int	ft_strlen(const char *s);
void testmoi(t_list_pre **test);
void child_process(int *comm);
void parent_process(int *comm);
void init_envp(struct s_list_pre *head, char **envp);
char *ft_value(char *str, t_list_pre *head);
void ft_lstadd_back_envp(t_list_pre *head, t_list_pre *new);
t_list_pre	*ft_envp_lstlast(t_list_pre *lst);
char *ft_key(char *str, t_list_pre *head);
t_list_pre * ft_env_lstnew(t_list_pre *head, char *envstr);
//void test_pipes(t_list_pre *head);

int	main(int argc, char **argv, char **envp)
{
	t_list_pre *head;
	
	init_envp(head, envp);
	test_pipes(head);
	return 0;
}

void init_envp(t_list_pre *head, char **envp)
{
	int			i;
	t_list_pre 	*current;

	i = 0;
	while (envp[i] != NULL)
		ft_lstadd_back_envp(head, ft_env_lstnew(head, envp[i++]));
	current = head;
	while (current)
	{
		(current)->k_size = ft_strlen((current)->key);
		(current)->v_size = ft_strlen((current)->value);
		(current) = (current)->next;
	}
}

void test_pipes(t_list_pre *head)
{
		int		fd[2];
		pid_t	pid;

		while(head->next)
		{
			pipe(fd);
			pid = fork();
			if (pid == 0)
			{
				close(fd[0]);
				write(fd[1], head->key, ft_strlen(head->key));
			}
			if (pid != 0)
				read(fd[0], )
		}
}

void create_pipe(void)
{
	pipe(comm);
	pid = fork();
	if (pid == -1)
		exit(1);
	else if (pid == 0)
		child_process(comm);
	else
		parent_process(comm);
}

void child_process(int *comm)
{
		close(comm[0]);
		write(comm[1], "test", 5);
}

void parent_process(int *comm)
{
		char *test;

		close(comm[1]);
		read(comm[0], test, 5);
		printf("%s", test);
}

void testmoi(t_list_pre **test)
{
	*test = (*test)->next;
}

t_list_pre * ft_env_lstnew(t_list_pre *head, char *envstr)
{
	t_list_pre	*new;

	new = malloc(sizeof (t_list_pre));
	new->key = ft_key(envstr, head);
	new->value = ft_value(envstr, head);
	new->next = NULL;
	return (new);
}

char *ft_key(char *str, t_list_pre *head)
{
	char	*retstr;
	int		i;

	i = 0;
	while (str[i] != '=')
		i++;
	retstr = malloc(sizeof (char) * i + 1);
	if (!retstr)
		exit(0);
	i = -1;
	while (str[++i] != '=')
		retstr[i] = str[i];
	retstr[i] = 0;
	return (retstr);
}

char *ft_value(char *str, t_list_pre *head)
{
	char	*retstr;
	int		i;
	int 	j;

	i = 0;
	j = 0;
	while (str[i] != '=')
		i++;
	while (str[j] != 0)
		j++;
	if (j - i == 1)
		return (NULL);
	retstr = malloc(sizeof (char) * j - i);
	if (!retstr)
		exit(0);
	i = 0;
	while (str[i] != '=')
		i++;
	j = 0;
	while (str[++i])
		retstr[j++] = str[i];
	return (retstr);
}


t_list_pre	*ft_envp_lstlast(t_list_pre *lst)
{
	t_list_pre	*tmp;

	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void ft_lstadd_back_envp(t_list_pre *head, t_list_pre *new)
{
	t_list_pre	*tmp;

	if (head)
	{
		tmp = ft_envp_lstlast(head);
		tmp->next = new;
	}
	else
		head = new;
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
