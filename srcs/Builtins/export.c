#include "minishell.h"



void export(t_list_tokken *current, t_parsing *bag)
{
	char		**arg;
	t_list_env	*new;

	if (!(current)->a_head)
	{
		env(bag);
		return ;
	}
	new = malloc(sizeof(t_list_env));
	new->next = NULL;
	arg = ft_splitt((current)->a_head->arg, '=');
	new->value = arg[1];
	new->key = arg[0];
	ft_lstadd_back_envp(bag, new);
}