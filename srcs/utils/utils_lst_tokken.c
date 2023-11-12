#include "minishell.h"

void	ft_t_relink(t_list_tokken *node)
{
	t_list_tokken	*tmp;

	tmp = node;
	if (node->next)
		node = node->next;
	if (tmp->cmd)
		free(tmp->cmd);
	free(tmp);
}

void ft_lstadd_back_token(t_list_tokken *node, t_list_tokken *new, t_parsing *bag)
{
	if (node)
		node->next = new;
	else
		bag->t_head = new;
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

t_list_tokken *ft_t_lstnew(t_parsing *bag)
{
	t_list_tokken	*instance;

	instance = (t_list_tokken *)malloc(sizeof(t_list_tokken));
	if (!instance)
		ft_error(MEMORY, bag);
	instance->cmd = NULL;
	instance->builtin_id = 7;
	instance->pipe_status = FALSE;
	instance->heredoc = NULL;
	instance->output = STDOUT_FILENO;
	instance->input = STDIN_FILENO;
	instance->append = -1;
	instance->pipe_status = FALSE;
	instance->a_head = NULL;
	instance->next = NULL;
	return (instance);
}
