#include "minishell.h"

void	tokkenizer(t_parsing *sac)
{
	t_list_pre		*current;
	t_list_tokken	*tokken;

	current = *(sac->p_head);
	while (current)
	{
		ft_lstadd_back_tokken(sac);
		check_commands(current, sac);
		check_builtins(current, sac);
		check_redirections(current, sac);
		check_arguments(current, sac);
		current = current->next;
	}
}

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


/*
 * how to check if command is valid?
 */
void	check_commands(char *pre_tokken, t_parsing *sac)
{

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

void			check_arguments(char *pre_tokken, t_parsing *sac);