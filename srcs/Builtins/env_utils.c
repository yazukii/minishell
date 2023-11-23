/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:01:51 by yidouiss          #+#    #+#             */
/*   Updated: 2023/11/23 18:01:51 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

t_list_env	*env_lstlast(t_list_env *lst)
{
	t_list_env	*tmp;

	tmp = lst;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
	}
	return (tmp);
}

void env_add_back(t_list_env **env, t_list_env *new)
{
	t_list_env	*tmp;

	if (*env)
	{
		tmp = env_lstlast(*env);
		tmp->next = new;
	}
	else
		*env = new;
}