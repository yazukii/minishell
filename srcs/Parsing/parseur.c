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

int	ft_number_args(t_list_tokken *current)
{
	t_list_arg	*a_current;
	int			i;

	i = 0;
	a_current = current->a_head;
	while (a_current)
	{
		i++;
		a_current = a_current->next;
	}
	return (i);
}

void	clean_end_space(t_parsing *bag)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (bag->input[i])
	{
		i++;
		j++;
	}
	i--;
	while (bag->input[i] == ' ')
		i--;
	if (i + 1 == j)
		return ;
	tmp = malloc(sizeof (char) * i + 2);
	if (!tmp)
		ft_error(MEMORY, bag);
	ft_strlcpy(tmp, bag->input, i + 2);
	free(bag->input);
	bag->input = tmp;
}

void	tokkenizer(t_parsing *bag)
{
	bag->can_exp = TRUE;
	bag->in_double = FALSE;
	bag->in_simple = FALSE;
	fill_tokkens_recursive(bag);
}
