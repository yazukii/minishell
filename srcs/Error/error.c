/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:05:06 by yidouiss          #+#    #+#             */
/*   Updated: 2023/07/26 18:57:35 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delone(t_list_pre *lst)
{
    if (!lst)
        return ;
    free(lst->pre_tokken);
    free(lst);
}

void    freelist(t_list_pre **p_head)
{
    t_list_pre	*tmp;
    t_list_pre	*t;

    t = *p_head;
    while (t)
    {
        tmp = t->next;
        delone(t);
        t = tmp;
    }
    *p_head = NULL;
}

void    freebag(t_parsing *bag)
{
    if (bag->input)
       free(bag->input);
    if (bag->key)
        free(bag->key);
    if (*bag->p_head)
        freelist(bag->p_head);
}

void ft_error(int ERRNUMBER, t_parsing *bag)
{
    if (ERRNUMBER == MEMORY)
        printf( "Memory error\n");
    if (ERRNUMBER == ENVP)
        printf( "Environement variable %s doesn't exist\n", bag->key->key);
    freebag(bag);
}
