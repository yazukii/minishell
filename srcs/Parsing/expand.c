/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:44:03 by yidouiss          #+#    #+#             */
/*   Updated: 2023/11/23 23:17:21 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand(t_parsing *bag)
{
	while (bag->input[bag->index])
	{
		if (bag->input[bag->index] == '$' && \
		state_quote(bag, bag->input[bag->index]))
		{
			if (check_env(bag))
			{
				clean_input(bag);
				bag->index += bag->key->k_size;
				bag->has_expanded = FALSE;
			}
		}
		bag->index++;
	}
}

void	replace_sequence(t_parsing *bag, char *r_str, int *r_index)
{
	int	i;

	i = 0;
	while (i < bag->key->v_size)
		r_str[(*r_index)++] = bag->key->value[i++];
}

void	clean_input(t_parsing *bag)
{
	char	*r_str;
	int		r_index;

	r_index = 0;
	r_str = ft_calloc(ft_strlen(bag->input) - (bag->key->k_size + 1) \
	+ bag->key->v_size + 1, sizeof (char));
	if (!r_str)
		ft_error(MALLOC, bag);
	while (bag->input[bag->i])
	{
		if (bag->input[bag->i] == '$' && !(bag->has_expanded) && \
		ft_strcmp(&bag->input[bag->i + 1], bag->key->key, bag->key->k_size))
		{
			replace_sequence(bag, r_str, &r_index);
			bag->i += bag->key->k_size + 1;
			bag->has_expanded = TRUE;
		}
		else
			r_str[r_index++] = bag->input[bag->i++];
	}
	free(bag->input);
	bag->input = r_str;
	bag->i = 0;
}

BOOL	check_env(t_parsing *bag)
{
	int			tmp;
	t_list_env	*current;

	current = bag->env_head;
	tmp = bag->index + 1;
	while (current)
	{
		if (ft_strcmp(&bag->input[tmp], (current)->key, (current)->k_size))
		{
			bag->key = current;
			return (TRUE);
		}
		(current) = (current)->next;
	}
	return (FALSE);
}
