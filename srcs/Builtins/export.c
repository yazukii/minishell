#include "minishell.h"



void	export(t_parsing *bag)
{
	char		**arg;
	t_list_env	*new;

	if (!(bag->t_head)->a_head)
	{
		env(bag);
		return ;
	}
	new = malloc(sizeof(t_list_env));
	new->next = NULL;
	arg = ft_splitt((bag->t_head)->a_head->arg, '=');
	new->value = arg[1];
	new->key = arg[0];
	ft_lstadd_back_envp(bag, new);
}