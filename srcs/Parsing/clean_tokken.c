#include "minishell.h"

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
                {
                    current->pre_tokken[i] = current->pre_tokken[i + 1];
                    i++;
                }
            }
            i++;
        }
        i = 0;
        current = current->next;
    }
}

void clean_std(t_parsing *bag, t_list_tokken *current)
{
	t_list_tokken	*tmp;
	while (current)
	{
		tmp = current->next;
		if (current->redir_id >= 0)
		{
			ft_t_relink(current);
			current = tmp;
		}
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