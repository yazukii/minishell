/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:44:03 by yidouiss          #+#    #+#             */
/*   Updated: 2023/11/23 23:28:04 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parseur(t_parsing *bag)
{
	expand(bag);
	clean_end_space(bag);
	pre_tokken(bag, bag->input);
	pre_tokken_size(bag);
	tokkenizer(bag);
	get_option(bag);
	refactor_redir(bag);
	return (0);
}

void	refactor_redir(t_parsing *bag)
{
	t_list_tokken	*first;
	t_list_tokken	*last;
	t_list_tokken	*current;

	first = bag->t_head;
	last = ft_t_lstlast(bag->t_head);
	current = bag->t_head;
	while (current)
	{
		if (current->output != STDOUT_FILENO)
		{
			first->output = current->output;
			current->output = STDOUT_FILENO;
		}
		if (current->input != STDIN_FILENO)
		{
			last->input = current->input;
			current->input = STDIN_FILENO;
		}
		current = current->next;
	}
}

void	get_option(t_parsing *bag)
{
	t_list_tokken	*current;

	current = bag->t_head;
	while (current)
	{
		current->exec = fill_exec(current, bag);
		current = current->next;
	}
}

char	**fill_exec(t_list_tokken *current, t_parsing *bag)
{
	char		**ret;
	t_list_arg	*a_current;
	int			i;
	int			len;

	i = 1;
	if (current->a_head)
		a_current = current->a_head;
	len = ft_number_args(current);
	ret = malloc(sizeof (char *) * len + 2);
	if (!ret)
		ft_error(MEMORY, bag);
	ret[0] = ft_strdup(current->cmd);
	while (len)
	{
		ret[i++] = ft_strdup(a_current->arg);
		a_current = a_current->next;
		len--;
	}
	ret[i] = NULL;
	return (ret);
}
