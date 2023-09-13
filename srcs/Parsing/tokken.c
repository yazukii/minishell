#include "minishell.h"

void	check_redirections(t_list_pre *current, t_parsing *sac)
{
	if (ft_strcmp(current->pre_tokken, "<", current->size))
		(ft_t_lstlast(*(sac->t_head)))->redir_id = LEFT;
	if (ft_strcmp(current->pre_tokken, ">", current->size))
		(ft_t_lstlast(*(sac->t_head)))->redir_id = RIGHT;
	if (ft_strcmp(current->pre_tokken, ">>", current->size))
		(ft_t_lstlast(*(sac->t_head)))->redir_id = APPEND;
	if (ft_strcmp(current->pre_tokken, "<<", current->size))
		(ft_t_lstlast(*(sac->t_head)))->redir_id = HEREDOC;
	if ((ft_t_lstlast(*(sac->t_head)))->redir_id)
		(ft_t_lstlast(*(sac->t_head)))->type = REDIRECTION;
}

void			check_arguments(t_list_pre *current, t_parsing *sac)
{
    (void)current;
    (void)sac;
}
/*
 * how to check if command is valid?
 */
void	check_commands(t_list_pre *current, t_parsing *sac)
{
    (void)current;
    (void)sac;
}

void	check_builtins(t_list_pre *current, t_parsing *sac)
{
	int			j;

	j = 0;
	while (sac->builtins[j])
	{
		if (ft_strcmp(current->pre_tokken, sac->builtins[j], current->size))
		{
			(ft_t_lstlast(*(sac->t_head)))->builtin_id = j;
			(ft_t_lstlast(*(sac->t_head)))->type = BUILTINS;
		}
		j++;
	}
}
/*
void	tokkenizer(t_parsing *sac)
{
    t_list_pre		*current;
    t_list_tokken	*tokken;

    //(void)tokken;
    current = *(sac->p_head);
    while (current)
    {
        ft_lstadd_back_token(sac);
        check_commands(current, sac);
        check_builtins(current, sac);
        check_redirections(current, sac);
        check_arguments(current, sac);
        current = current->next;
    }
}*/