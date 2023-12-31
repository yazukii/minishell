/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:44:03 by yidouiss          #+#    #+#             */
/*   Updated: 2023/11/23 21:44:03 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	tmp = ft_calloc(i + 2, sizeof (char));
	if (!tmp)
		ft_error(MALLOC, bag);
	ft_strlcpy(tmp, bag->input, i + 2);
	free(bag->input);
	bag->input = tmp;
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

int	ft_strcmp(char const *str, char const *model, int size)
{
	int	i;

	i = 0;
	while (str[i] == model[i] && str[i] && model[i])
		i++;
	if (model[i] == '\0' && i == size)
		return (TRUE);
	return (FALSE);
}

void	pre_tokken_size(t_parsing *bag)
{
	t_list_pre	*current;
	int			i;

	i = 0;
	current = bag->p_head;
	while (current)
	{
		while (current->pre_tokken[i])
			i++;
		current->size = i;
		current = current->next;
		i = 0;
	}
}

BOOL	state_quote(t_parsing *bag, char c)
{
	if (c == '\"' && bag->in_double)
		bag->in_double = FALSE;
	else if (c == '\"' && !bag->in_double)
	{
		bag->in_double = TRUE;
		bag->can_exp = TRUE;
	}
	if (c == '\'' && bag->in_simple && !bag->in_double)
	{
		bag->in_simple = FALSE;
		bag->can_exp = TRUE;
	}
	else if (c == '\'' && !bag->in_simple && !bag->in_double)
	{
		bag->in_simple = TRUE;
		bag->can_exp = FALSE;
	}
	return (bag->can_exp);
}
