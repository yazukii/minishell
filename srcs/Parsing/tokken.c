#include "minishell.h"

void	tokkenizer(t_parsing *bag)
{
t_list_pre		*current;

current = bag->p_head;
bag->can_exp = TRUE;
bag->in_double = FALSE;
bag->in_simple = FALSE;
clean_single_quote(bag);
clean_double_quote(bag);
while (current)
{
    if (!ft_lstadd_back_token(bag, ft_t_lstnew()))
        ft_error(MEMORY, bag);
    check_builtins(current, bag);
    check_redirections(current, bag);
    check_arguments(current, bag);
    current = current->next;
}
check_std(bag);
fill_args(bag);
}

void heredoc(t_list_tokken *current, t_parsing *bag)
{
    pid_t child;

   child = fork();
   if (child == -1)
       ft_error(FORK, bag);
   if (child == 0)
   {
       while ()
   }
}

void check_std(t_parsing *bag)
{
    t_list_tokken *current;

    current = bag->t_head;
    while (current)
    {
        if (current->redir_id == INPUT || current->redir_id == OUTPUT || current->redir_id == APPEND)
        {
            if (current->redir_id == OUTPUT || current->redir_id == APPEND)
                bag->fd = open(current->next->arg, O_WRONLY);
            if (current->redir_id == INPUT)
                bag->fd = open(current->next->arg, O_RDONLY);
            if (bag->fd == -1)
                ft_error(FD, bag);
            if (current->redir_id == OUTPUT || current->redir_id == APPEND)
                current->output = bag->fd;
            if (current->redir_id == INPUT)
                current->input = bag->fd;
        }
        if (current->redir_id == HEREDOC)
            heredoc(current, bag);
        current = current->next;
    }
}

void	clean_double_quote(t_parsing *bag)
{
	t_list_pre	*current;
	int			i;

	i = 0;
	current = bag->p_head;
	while (current)
	{
		while (current->pre_tokken[i])
		{
			if (current->pre_tokken[i] == '\"')
			{
				while (current->pre_tokken[i + 1])
					current->pre_tokken[i] = current->pre_tokken[i + 1];
				i++;
			}
		}
		i = 0;
		current = current->next;
	}
}


void	clean_single_quote(t_parsing *bag)
{
	t_list_pre	*current;
	int			i;

	i = 0;
	current = bag->p_head;
	while (current)
	{
		while (current->pre_tokken[++i])
		{
			state_quote(bag, current->pre_tokken[i]);
			if (current->pre_tokken[i] == '\'' && !bag->in_double)
			{
				while (current->pre_tokken[i + 1])
					current->pre_tokken[i] = current->pre_tokken[i + 1];
				i++;
			}
		}
		i = 0;
		current = current->next;
	}
}

void	fill_args(t_parsing *bag)
{
	t_list_tokken	*current;
    int              fd;

	current = bag->t_head;
	while (current)
	{
		if (current->type == COMMAND || current->type == BUILTINS)
		{
			if (allocate_args(current) == FALSE) {
                ft_error(MEMORY, bag);
            }
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

int	allocate_args(t_list_tokken *node)
{
	t_list_tokken	*current;
	int				i;

	i = 0;
    node->args = malloc(sizeof (char *) * ft_t_arglstsize(node));
	if (!node->args)
		return (FALSE);
	current = node->next;
	while (current->type == ARGUMENT)
	{
        node->args[i] = current->arg;
		current = current->next;
		i++;
	}
	return (TRUE);
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
