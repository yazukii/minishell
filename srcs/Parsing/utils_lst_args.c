#include "minishell.h"

t_list_arg	*ft_lstadd_back_arg(t_parsing *bag, t_list_arg *new)
{
	t_list_arg	*tmp;

	if (!new)
		return (NULL);
	if (bag->t_head->a_head)
	{
		tmp = ft_a_lstlast(ft_t_lstlast(bag->t_head)->a_head);
		tmp->next = new;
	}
	else
		bag->t_head->a_head = new;
	return (new);
}

t_list_arg	*ft_a_lstlast(t_list_arg *lst)
{
	t_list_arg	*tmp;

	tmp = lst;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
	}
	return (tmp);
}

t_list_arg	*ft_a_lstnew(void)
{
	t_list_arg	*instance;

	instance = (t_list_arg *) malloc(sizeof(t_list_arg));
	if (!instance)
		return (NULL);
	instance->input = 1;
	instance->output = 0;
	instance->arg = NULL;
	instance->append = -1;
	instance->next = NULL;
	return (instance);
}