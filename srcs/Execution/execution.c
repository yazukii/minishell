#include "../headers/minishell.h"

int execution(t_parsing *bag)
{
	t_list_tokken	*tmp;
	tmp = bag->t_head;
	while (tmp)
	{
		choose_builtin(bag);
		tmp = tmp->next;
	}
	return (0);
}

void	exec_cmd(t_parsing *bag)
{
	(void)bag;
	return ;
}