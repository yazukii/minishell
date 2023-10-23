#include "minishell.h"

t_list_pre	*ft_pre_lstlast(t_list_pre *lst)
{
	t_list_pre	*tmp;

	tmp = lst;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
	}
	return (tmp);
}

t_list_pre	*ft_pre_lstadd_back(t_list_pre **lst, t_list_pre *new)
{
	t_list_pre	*tmp;

	if (*lst)
	{
		tmp = ft_pre_lstlast(*lst);
		tmp->next = new;
	}
	else
		*lst = new;
	return (new);
}

t_list_pre *ft_pre_lstnew(char *pre_tokken,t_parsing *bag)
{
	t_list_pre	*instance;

	instance = (t_list_pre *) malloc(sizeof(t_list_pre));
	if (!instance)
		ft_error(MEMORY, bag);
	instance->pre_tokken = pre_tokken;
	instance->next = NULL;
	return (instance);
}
