#include "minishell.h"

/*
 * 	env:
 * 		-
 */


int	env(t_list_env *head, int fd)
{
	t_list_env	*tmp;
	int		i;

	i = 0;
	tmp = head;
	while (tmp)
	{
		while (tmp->key[i])
			write(fd, &(tmp->key[i++]), 1);
		i = 0;
		write(fd, "=", 1);
		while (tmp->value[i])
			write(fd, &(tmp->value[i++], 1));
		tmp = tmp->next;
		i = 0;
	}
	return 1;
}