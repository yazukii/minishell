#include "minishell.h"



int ft_export(t_list_tokken *current, t_parsing *bag)
{
	char		**arg;
	t_list_env	*new;

	if (!(current)->a_head)
	{
		ft_env(bag);
		return (EXIT_FAILURE);
	}
	new = malloc(sizeof(t_list_env));
	new->next = NULL;
	arg = ft_splitt((current)->a_head->arg, '=');
	new->value = arg[1];
	new->key = arg[0];
	ft_lstadd_back_envp(bag, new);
	return (EXIT_SUCCESS);
}