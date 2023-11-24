/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tokken.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:44:03 by yidouiss          #+#    #+#             */
/*   Updated: 2023/11/23 23:14:52 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_redirections(t_list_pre *current)
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
		return (PIPE);
	return (NO_REDIR);
}

void	check_builtins(t_list_tokken *current, t_parsing *bag)
{
	int	j;

    j = 0;
    while (bag->builtins[j])
    {
        if (ft_strcmp(current->cmd, bag->builtins[j], current->size))
            current->builtin_id = j;
        j++;
    }
}
