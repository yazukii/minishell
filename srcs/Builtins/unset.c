#include "minishell.h"

/* unset:
 *  - on va jusqu'a l'avant dernier pour unset l'element de la liste
 */

int	unset(t_list_env *head, char *key)
{
	t_list_env	*tmp;
	t_list_env	*hook;

	tmp = head;
	while (tmp->key != key && tmp)
		tmp = tmp->next;
	if (!tmp)
		return (0);	// err
	hook = tmp->next;
	free(tmp);
	tmp = lstlast(head);
	tmp->next = hook;
	return (1);
}