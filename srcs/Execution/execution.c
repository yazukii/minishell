#include "../headers/minishell.h"

/* we need to fork for each t_tokken
 * then use the pipe() to get the communication going
 * check if it's the last command to not creat a pipe
 * wait for all the previous commands to be executed
 * how to make it so that the previous cmd execution is the input for the next cmd?
 * */
void	process_management(t_parsing *bag)
{
	int	id;
	int	fd[2];
	int i;
	t_list_tokken *current;

	i = number_cmds(bag->t_head);
	current = bag->t_head;
	while (i-- > 0)
	{
		id = fork();
		if (id == -1)
			ft_error(FORK, bag);
		else if (id == 0)
			child_process(current, bag, fd);
		else
			bag->pipestr = parent_process(current, bag, fd);
		current = current->next;
	}
}

char *parent_process(t_list_tokken *current, t_parsing *bag, int *fd)
{
	ssize_t	nbytes;
	char 	*buff;
	char	*retstr;

	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	nbytes = 1;
	buff = malloc(sizeof (char) * 1024);
	while (nbytes > 0)
	{
		nbytes = read(STDIN_FILENO, buff, sizeof(buff));
		retstr = ft_strjoin(retstr, buff);
	}
	free(buff);
	return (retstr);
}

void child_process(t_list_tokken *current, t_parsing *bag, int *fd)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	choose_builtin(current, bag);
	ft_error(EXECVE, bag);
}

int number_cmds(t_list_tokken *head)
{
	int				i;
	t_list_tokken	*current;

	i = 0;
	current = head;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}
