#include "minishell.h"

void check_std(t_parsing *bag)
{
    t_list_tokken *current;

    current = bag->t_head;
    while (current)
    {
        if (current->redir_id == INPUT || current->redir_id == OUTPUT || current->redir_id == APPEND)
        	std_check(bag, current);
        if (current->redir_id == HEREDOC)
            heredoc(current, bag);
        current = current->next;
    }
	current = bag->t_head;
	while (current->next)
	{
		if (current->redir_id != NO_REDIR && current->next->redir_id != NO_REDIR)
			ft_error(SYNTAX, bag);
		current = current->next;
	}
	current = bag->t_head;
	clean_std(bag,current);
}

void	std_check(t_parsing *bag, t_list_tokken *current)
{
	if (current->redir_id == INPUT)
		bag->fd = open(current->next->arg, O_RDONLY);
	if (bag->fd == -1 && current->redir_id == INPUT)
		ft_error(FD, bag);
	if (current->redir_id == OUTPUT || current->redir_id == APPEND)
	{
		bag->fd = open(current->next->arg, O_WRONLY | O_CREAT, 777);
		if (bag->fd == -1)
			ft_error(FILE_CREATIION, bag);
		current->output[0] = bag->fd;
	}
	if (current->redir_id == INPUT)
		current->input[0] = bag->fd;
}

void	check_redirections(t_list_pre *current, t_parsing *bag)
{
    if (ft_strcmp(current->pre_tokken, "<", current->size))
        (ft_t_lstlast(bag->t_head))->redir_id = INPUT;
    if (ft_strcmp(current->pre_tokken, ">", current->size))
        (ft_t_lstlast(bag->t_head))->redir_id = OUTPUT;
    if (ft_strcmp(current->pre_tokken, ">>", current->size))
        (ft_t_lstlast(bag->t_head))->redir_id = APPEND;
    if (ft_strcmp(current->pre_tokken, "<<", current->size))
        (ft_t_lstlast(bag->t_head))->redir_id = HEREDOC;
    if (ft_strcmp(current->pre_tokken, "|", current->size))
    {
        (ft_t_lstlast(bag->t_head))->redir_id = PIPE;
        bag->pipe_flag = TRUE;
    }
    if ((ft_t_lstlast(bag->t_head))->redir_id != NO_REDIR)
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
    else if (ft_t_lstlast(bag->t_head)->type == NO_TYPE)
    {
        ft_t_lstlast(bag->t_head)->type = ARGUMENT;
        ft_t_lstlast(bag->t_head)->arg = current->pre_tokken;
    }
}

void	check_builtins(t_list_pre *current, t_parsing *bag)
{
    int			j;

    j = 0;
	if (ft_t_lstlast(bag->t_head)->type != NO_TYPE)
		return ;
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