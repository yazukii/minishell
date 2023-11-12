#include "minishell.h"

int env(t_parsing *bag)
{
	t_list_env *tmp;

	tmp = bag->env_head;
	while (tmp)
	{
		printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
	return (0);
}
