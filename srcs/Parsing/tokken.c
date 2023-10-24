#include "minishell.h"

void	fill_tokken(t_parsing *bag)
{
	t_list_pre			*tmp;
	enum e_redirections	redir_type;

	tmp = bag->p_head;
	while (tmp)
	{
		if (tmp == bag->p_head || bag->pipe_flag)
			create_cmd(bag, &tmp);
		redir_type = redir(bag, &tmp);
		if (!bag->pipe_flag)
		{
			fill_cmd(bag, tmp, redir_type);
			tmp = tmp->next;
		}
	}
}

void fill_cmd(t_parsing *bag, t_list_pre *tmp, enum e_redirections redir_type)
{
	t_list_arg *arg_node;

	ft_lstadd_back_arg(bag, ft_a_lstnew(bag));
	arg_node = ft_a_lstlast(ft_t_lstlast(bag->t_head)->a_head);
	arg_node->arg = malloc(sizeof (char) * tmp->size + 1);
	if (!arg_node->arg)
		ft_error(MEMORY, bag);
	ft_strlcpy(arg_node->arg, tmp->pre_tokken, tmp->size + 1);
	management_redir(arg_node, redir_type, bag);
}

void management_redir(t_list_arg *arg_node, enum e_redirections redir_type, t_parsing *bag)
{
	if (redir_type == INPUT)
		arg_node->input = open(arg_node->arg, O_RDONLY);
	if (arg_node->input == -1 && redir_type == INPUT)
		ft_error(FD, bag);
	if (redir_type == OUTPUT)
	{
		arg_node->output = open(arg_node->arg, O_WRONLY | O_CREAT, 0777);
		if (arg_node->output == -1)
			ft_error(FILE_CREATION, bag);
	}
	if (redir_type == APPEND)
	{
		arg_node->append = open(arg_node->arg, O_WRONLY | O_CREAT, 0777);
		if (arg_node->append == -1)
			ft_error(FILE_CREATION, bag);
	}
}

// faut utiliser les doubles pointeur
// test = 0x1; &test = 0x2 (0x1);mod(&test: 0x1 => 0x5); test=0x5; &test=0x2;
int	redir(t_parsing *bag, t_list_pre **tmp)
{
	int 			redir_id;
	t_list_tokken	*last;

	redir_id = (check_redirections(*tmp, bag));
	last = ft_t_lstlast(bag->t_head);
	if (redir_id != NO_REDIR && (*tmp)->next)
	{
		*tmp = (*tmp)->next;
		if (check_redirections(*tmp, bag) !=  NO_REDIR)
			ft_error(SYNTAX, bag);
	}
	if (redir_id == PIPE && last->pipe_status == TRUE)
		ft_error(SYNTAX, bag);
	else if (redir_id == PIPE && last->pipe_status != TRUE)
		last->pipe_status = TRUE;
	return (redir_id);
}

void	create_cmd(t_parsing *bag, t_list_pre **tmp)
{
	t_list_tokken *last;

	ft_lstadd_back_token(bag, ft_t_lstnew(bag));
	last = ft_t_lstlast(bag->t_head);
	check_builtins(*tmp, bag);
	if (last->builtin_id == NO_BUILTIN)
	{
		last->cmd = malloc(sizeof (char) * (*tmp)->size);
		if (!last->cmd)
			ft_error(MEMORY, bag);
		ft_strlcpy(last->cmd, (*tmp)->pre_tokken, (*tmp)->size + 1);
	}
	bag->pipe_flag = FALSE;
	if ((*tmp)->next)
		*tmp = (*tmp)->next;
}
