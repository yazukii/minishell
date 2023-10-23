#include "minishell.h"

int check_redirections(t_list_pre *current, t_parsing *bag)
{
    if (ft_strcmp(current->pre_tokken, "<", current->size))
		return (INPUT);
    if (ft_strcmp(current->pre_tokken, ">", current->size))
        return (OUTPUT);
    if (ft_strcmp(current->pre_tokken, ">>", current->size))
		return (APPEND);
    if (ft_strcmp(current->pre_tokken, "<<", current->size))
		return (HEREDOC);
    if (ft_strcmp(current->pre_tokken, "|", current->size))
    {
		bag->pipe_flag = TRUE;
		return (PIPE);
    }
	return (NO_REDIR);
}

void	check_builtins(t_list_pre *current, t_parsing *bag)
{
    int			j;

    j = 0;
    while (bag->builtins[j])
    {
        if (ft_strcmp(current->pre_tokken, bag->builtins[j], current->size))
            (ft_t_lstlast(bag->t_head))->builtin_id = j;
        j++;
    }
}