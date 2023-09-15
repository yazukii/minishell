#include "minishell.h"

void	tokkenizer(t_parsing *bag)
{
	t_list_pre		*current;
	t_list_tokken	*tokken;

	current = bag->p_head;
	bag->can_exp = TRUE;
	bag->in_double = FALSE;
	bag->in_simple = FALSE;
	if (!clean_single_quote(bag))
		ft_error(MEMORY, bag);
	while (current)
	{
		if (!ft_lstadd_back_token(bag, ft_t_lstnew()))
			ft_error(MEMORY, bag);
		check_builtins(current, bag);
		check_redirections(current, bag);
		check_arguments(current, bag);
		current = current->next;
	}
	fill_args(bag);
}

int	clean_single_quote(t_parsing *bag)
{
	t_list_pre	*current;
	char		*new;
	int			i;
	int			j;

	i = 0;
	j = 0;
	current = bag->p_head;
	while (current)
	{
		new = malloc(sizeof (char) * ft_strlen(current->pre_tokken) + 1);
		while (current->pre_tokken[i])
		{
			if (current->pre_tokken[i] == '\'' && \
					!state_quote(bag, current->pre_tokken[i]))
				i++;
			new[j++] = current->pre_tokken[i];
			i++;
		}
		new[j] = 0;
		j = 0;
		i = 0;
		current = current->next;
	}
}

void	fill_args(t_parsing *bag)
{
	t_list_tokken	*current;

	current = bag->t_head;
	while (current)
	{
		if (current->type == COMMAND || current->type == BUILTINS)
		{
			if (allocate_args(current) == FALSE)
				ft_error(MEMORY, bag);
		}
		current = current->next;
	}
	clean_lst(bag->t_head);
}

void	clean_lst(t_list_tokken *head)
{
	t_list_tokken	*current;
	t_list_tokken	*hook;
	t_list_tokken	*tmp;

	current = head;
	while (current)
	{
		if (current->type == COMMAND || current->type == BUILTINS)
			hook = current;
		if (current->type == ARGUMENT)
		{
			tmp = current;
			current = current->next;
			free(tmp);
			hook->next = current;
		}
		else
			current = current->next;
	}
}

int	allocate_args(t_list_tokken *head)
{
	t_list_tokken	*current;
	int				i;

	i = 0;
	head->args = malloc(sizeof (char *) * ft_t_arglstsize(current));
	if (!head->args)
		return (FALSE);
	current = head->next;
	while (current->type == ARGUMENT)
	{
		head->args[i] = current->arg;
		current = current->next;
		i++;
	}
	return (TRUE);
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
		ft_t_lstlast(bag->t_head)->arg = current->pre_tokken;
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
