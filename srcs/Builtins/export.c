#include "minishell.h"
/*
 * export:
 * 		- doesn't interact with signle quotes to be careful in parthing
 * 		- new values are put at the next to last element in the list
 * 		todo:
 * 		- code here lst_env_new
 * 		- separer l'input en key et value
 */


int	export(t_list_env *head, char *key, char *value)
{
	t_list_env	*tmp;
	t_list_env	*hook;
	t_list_env	*new;

	tmp = head;
	while (tmp->next->key != "_")
		tmp = tmp->next;
	new = lst_env_new(key, value);
	if (!new)
		return (1);
	hook = tmp->next;
	tmp->next = new;
	new->next = hook;
	return (0);
}