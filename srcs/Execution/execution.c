/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:44:03 by yidouiss          #+#    #+#             */
/*   Updated: 2023/11/23 21:44:03 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

/* we need to fork for each t_tokken
 * then use the pipe() to get the communication going
 * check if it's the last command to not creat a pipe
 * wait for all the previous commands to be executed
 * how to make it so that the previous cmd execution is the input for the next cmd?
 * */

void execution(t_parsing *bag, char **envp)
{
	if (!bag->t_head)
		ft_error(INPUT, bag);
	if (!(bag->t_head->next))
		ft_one_cmd(bag, envp);
	else
		ft_multi_cmd(bag, envp);
}
