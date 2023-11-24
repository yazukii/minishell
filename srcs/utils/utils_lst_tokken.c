/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst_tokken.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:44:03 by yidouiss          #+#    #+#             */
/*   Updated: 2023/11/23 21:44:03 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_t_relink(t_list_tokken *node)
{
	t_list_tokken	*tmp;

	tmp = node;
	if (node->next)
		node = node->next;
	if (tmp->cmd)
		free(tmp->cmd);
	free(tmp);
}

void	ft_lstadd_back_token(t_list_tokken *node, \
t_list_tokken *new, t_parsing *bag)
{
	if (node)
		ft_t_lstlast(node)->next = new;
	else
		bag->t_head = new;
}

t_list_tokken	*ft_t_lstlast(t_list_tokken *lst)
{
	t_list_tokken	*tmp;

	tmp = lst;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
	}
	return (tmp);
}

t_list_tokken	*ft_t_lstnew(t_parsing *bag)
{
	t_list_tokken	*instance;

	instance = malloc(sizeof(t_list_tokken));
	if (!instance)
		ft_error(MEMORY, bag);
	instance->builtin_id = NO_BUILTIN;
	instance->cmd = NULL;
	instance->heredoc = NULL;
	instance->a_head = NULL;
	instance->output = STDOUT_FILENO;
	instance->input = STDIN_FILENO;
	instance->append = -1;
	instance->exec = NULL;
	instance->pipe_status = FALSE;
	instance->next = NULL;
	return (instance);
}
