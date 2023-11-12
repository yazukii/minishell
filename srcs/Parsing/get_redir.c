#include "minishell.h"


void r_fill_redir(t_parsing *bag)
{
	t_list_pre *current;

	current = find_redir(bag);
	if (!current)
		return ;
	if (check_redir(current->pre_tokken) == HEREDOC)
		get_heredoc(current, bag);
	else if (check_redir(current->pre_tokken) == APPEND || check_redir(current->pre_tokken) == INPUT || check_redir(current->pre_tokken) == OUTPUT)
		cmd_redir(current, bag);
	clean_redir(bag);
	current = find_redir(bag);
	if (current)
		r_fill_redir(bag);
}

/*now that we have assigned the fd to the command
 * we clean the corresponding redir in the pre_tokken list
 * to find the position of the redir to clean we use find_redir
 * to find the position of the pre_tokken before we use find_before_redir
 * if there is a before then you relink to the before
 * else you relink to the pointer to the list*/
void clean_redir(t_parsing *bag)
{
	t_list_pre	*tmp;
	t_list_pre	*next;
	t_list_pre	*before;

	tmp = find_redir(bag);
	before = find_before_redir(bag);
	next = tmp->next;
	free(tmp->pre_tokken);
	free(tmp);
	tmp =  next;
	next = tmp->next;
	free(tmp->pre_tokken);
	free(tmp);
	if (before)
		before->next = next;
	else
		*bag->p_head = next;
}

t_list_pre *find_before_redir(t_parsing *bag)
{
	t_list_pre *current;

	current = *bag->p_head;
	while (current->next && check_redir(current->next->pre_tokken) != PIPE)
	{
		if (check_redir(current->next->pre_tokken))
			return (current);
		current = current->next;
	}
	return (NULL);
}

/* get the redir pre_token
 * check if next is not null
 * if output create file and get fd
 * if input get file fd or error
 * clean les pre_token liés*/
void cmd_redir(t_list_pre *current, t_parsing *bag)
{
	int	redir_type;
	t_list_tokken	*cmd_node;

	cmd_node = ft_t_lstlast(*bag->t_head);
	redir_type = check_redir(current->pre_tokken);
	if (redir_type && !current->next->pre_tokken)
		ft_error(SYNTAX, bag);
	if (redir_type == INPUT)
	{
		cmd_node->input = open(current->pre_tokken, O_RDONLY);
		if (cmd_node->input == -1)
			ft_error(FD, bag);
	}
	else if (redir_type == OUTPUT)
	{
		cmd_node->output = open(current->pre_tokken, O_WRONLY | O_CREAT, 0777);
		if (cmd_node->output == -1)
			ft_error(FILE_CREATION, bag);
	}
	else if (redir_type == APPEND)
	{
		cmd_node->append = open(current->pre_tokken, O_WRONLY | O_CREAT, 0777);
		if (cmd_node->append == -1)
			ft_error(FILE_CREATION, bag);
	}
}

t_list_pre *find_redir(t_parsing *bag)
{
	t_list_pre *current;

	current = *bag->p_head;
	while (current && check_redir(current->pre_tokken) != PIPE)
	{
		if (check_redir(current->pre_tokken) != -1)
			return (current);
		current = current->next;
	}
	return (NULL);
}