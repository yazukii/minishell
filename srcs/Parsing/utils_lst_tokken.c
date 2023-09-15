#include "minishell.h"

int	ft_t_arglstsize(t_list_tokken *lst)
{
	int	i;

	i = 0;
	while (lst->type == ARGUMENT)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list_tokken	*ft_lstadd_back_token(t_parsing *sac, t_list_tokken *new)
{
	t_list_tokken	*tmp;

	if (!new)
		return (NULL);
	if (*(sac->t_head))
	{
		tmp = ft_t_lstlast(sac->t_head);
		tmp->next = new;
	}
	else
		*(sac->t_head) = new;
	return (new);
}

t_list_tokken	*ft_t_lstlast(t_list_tokken *lst)
{
	t_list_tokken	*tmp;

	tmp = lst;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
	}
	return (tmp);
}

t_list_tokken	*ft_t_lstnew(void)
{
	t_list_tokken	*instance;

	instance = (t_list_tokken *) malloc(sizeof(t_list_tokken));
	if (!instance)
		return (NULL);
	instance->arg = NULL;
	instance->cmd = NULL;
	instance->type = -1;
	instance->redir_id = -1;
	instance->builtin_id = -1;
	instance->next = NULL;
	instance->input = 0;
	instance->output = 1;
	return (instance);
}
