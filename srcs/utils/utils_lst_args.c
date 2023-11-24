/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:44:03 by yidouiss          #+#    #+#             */
/*   Updated: 2023/11/23 21:44:03 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list_arg	*ft_lstadd_back_arg(t_parsing *bag, t_list_arg *new)
{
	t_list_arg	*tmp;

	if (ft_t_lstlast(bag->t_head)->a_head)
	{
		tmp = ft_a_lstlast(ft_t_lstlast(bag->t_head)->a_head);
		tmp->next = new;
	}
	else
		ft_t_lstlast(bag->t_head)->a_head = new;
	return (new);
}

t_list_arg	*ft_a_lstlast(t_list_arg *lst)
{
	t_list_arg	*tmp;

	tmp = lst;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
	}
	return (tmp);
}

t_list_arg *ft_a_lstnew(char *str, t_parsing *bag)
{
	t_list_arg	*instance;

	instance = malloc(sizeof(t_list_arg *));
	if (!instance)
		ft_error(MEMORY, bag);
	instance->arg = str;
	instance->next = NULL;
	return (instance);
}

void free_p_args(t_parsing *bag)
{
	t_list_pre	*tmp;

	tmp = bag->p_head;
	bag->p_head = bag->p_head->next;
	free(tmp->pre_tokken);
	free(tmp);
}