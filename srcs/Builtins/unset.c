/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:44:03 by yidouiss          #+#    #+#             */
/*   Updated: 2023/11/23 21:44:03 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void env_delone(t_list_env *env)
{
	if (env == NULL || env->next == NULL)
		return; // Nothing to delete
	t_list_env *tmp = env->next;
	env->next = tmp->next;
	free(tmp);
}

int ft_unset(t_parsing *bag, t_list_tokken *current)
{
	char *key = current->a_head->arg;
	t_list_env *tmp = (bag->env_head);
	int		exit_status;

	exit_status = EXIT_SUCCESS;
	if (ft_strchr(key, '-') != NULL)
	{
		ft_putstr_fd("ft_unset: '", STDERR_FILENO);
		ft_putstr_fd(key, STDERR_FILENO);
		ft_putstr_fd("' :not a valid identifier: \n", STDERR_FILENO);
		exit_status = EXIT_FAILURE;
	}
	while (tmp && tmp->next)
	{
		if (ft_strncmp(tmp->next->key, key, 1024) == 0)
		{
			env_delone(tmp);
			return (exit_status);
		}
		tmp = tmp->next;
	}
	return (exit_status);
}
