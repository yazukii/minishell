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