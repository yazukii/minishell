#include "minishell.h"

t_list_pre	*ft_pre_lstlast(t_list_pre *lst)
{
	t_list_pre	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void ft_pre_lstadd_back(t_list_pre *node, t_list_pre *new, t_parsing *bag)
{
	if (node)
		node->next = new;
	else
		bag->p_head = new;
}

t_list_pre *ft_pre_lstnew(char *pre_tokken, t_parsing *bag)
{
	t_list_pre	*instance;

	instance = malloc(sizeof(t_list_pre));
	if (!instance)
		ft_error(MEMORY, bag);
	instance->pre_tokken = pre_tokken;
	instance->next = NULL;
	return (instance);
}
