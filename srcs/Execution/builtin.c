/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:44:03 by yidouiss          #+#    #+#             */
/*   Updated: 2023/11/23 21:44:03 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	ft_execute_builtin(t_list_tokken *current, t_parsing *bag)
{
	if (current->builtin_id == ECHO)
		return (ft_echo(current));
	if (current->builtin_id == CD)
		return (ft_cd(current, bag->cwd));
	if (current->builtin_id == PWD)
		return (ft_pwd(current, bag));
	if (current->builtin_id == EXPORT)
		return (ft_export(current, bag));
	if (current->builtin_id == UNSET)
		return (ft_unset(bag, current));
	if (current->builtin_id == ENV)
		return (ft_env(bag));
	if (current->builtin_id == EXIT)
	{
		free_all(bag);
		free_env(bag);
		exit(0);
	}
	return (EXIT_SUCCESS);
}
