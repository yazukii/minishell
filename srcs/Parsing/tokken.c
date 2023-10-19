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
    check_redirections(current, bag);
    check_arguments(current, bag);
    check_builtins(current, bag);
    current = current->next;
}
check_std(bag);
fill_args(bag);
}

void heredoc(t_list_tokken *current, t_parsing *bag)
{
    char    *str;
    char    *tmp;
    char    *eof;

    eof = current->next->arg;
    tmp = NULL;
    str = NULL;
    while (tmp != eof)
    {
        str = ft_strjoin(str, tmp);
        tmp = readline(BLU"heredoc$ "RESET);
    }
    bag->heredoc = str;
	ft_t_relink(current);
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

int	allocate_args(t_list_tokken *node)
{
	t_list_tokken	*current;
	int				i;

	i = 0;
    node->args = malloc(sizeof (char *) * ft_t_arglstsize(node));
	if (!(node->args))
		return (FALSE);
	current = node->next;
	while (current && current->type == ARGUMENT)
	{
		if (current->input[0] != 0)
			node->input[node->input_nbr++] = current->input[0];
		if (current->output[0] != 1)
			node->output[node->output_nbr++] = current->output[0];
        node->args[i] = current->arg;
		current = current->next;
		i++;
	}
	return (TRUE);
}
