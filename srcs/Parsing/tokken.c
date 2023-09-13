#include "minishell.h"

void	tokkenizer(t_parsing *bag)
{
	t_list_pre		*current;
	t_list_tokken	*tokken;

	current = bag->p_head;
	while (current)
	{
		if (!ft_lstadd_back_token(bag, ft_t_lstnew()))
			ft_error(MEMORY, bag);
		check_builtins(current, bag);
		check_redirections(current, bag);
		check_arguments(current, bag);
		current = current->next;
	}
	if (!clean_single_quote(bag))
		ft_error(MEMORY, bag);
}

int	clean_single_quote(t_parsing *bag)
{

}

void	check_redirections(t_list_pre *current, t_parsing *bag)
{
	if (ft_strcmp(current->pre_tokken, "<", current->size))
		(ft_t_lstlast(bag->t_head))->redir_id = LEFT;
	if (ft_strcmp(current->pre_tokken, ">", current->size))
		(ft_t_lstlast(bag->t_head))->redir_id = RIGHT;
	if (ft_strcmp(current->pre_tokken, ">>", current->size))
		(ft_t_lstlast(bag->t_head))->redir_id = APPEND;
	if (ft_strcmp(current->pre_tokken, "<<", current->size))
		(ft_t_lstlast(bag->t_head))->redir_id = HEREDOC;
	if (ft_strcmp(current->pre_tokken, "|", current->size))
	{
		(ft_t_lstlast(bag->t_head))->redir_id = PIPE;
		bag->pipe_flag = TRUE;
	}
	if ((ft_t_lstlast(bag->t_head))->redir_id)
		(ft_t_lstlast(bag->t_head))->type = REDIRECTION;
}

void	check_arguments(t_list_pre *current, t_parsing *bag)
{
	if (current == bag->p_head || bag->pipe_flag)
	{
		ft_t_lstlast(bag->t_head)->type = COMMAND;
		ft_t_lstlast(bag->t_head)->cmd = current->pre_tokken;
		bag->pipe_flag = FALSE;
	}
	else
	{
		ft_t_lstlast(bag->t_head)->type = ARGUMENT;
		ft_t_lstlast(bag->t_head)->args = current->pre_tokken;
	}
}

void	check_builtins(t_list_pre *current, t_parsing *bag)
{
	int			j;

	j = 0;
	while (bag->builtins[j])
	{
		if (ft_strcmp(current->pre_tokken, bag->builtins[j], current->size))
		{
			(ft_t_lstlast(bag->t_head))->builtin_id = j;
			(ft_t_lstlast(bag->t_head))->type = BUILTINS;
		}
		j++;
	}
}
