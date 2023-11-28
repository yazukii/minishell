/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:01:51 by yidouiss          #+#    #+#             */
/*   Updated: 2023/11/23 23:09:19 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_quote(char **str, t_parsing *bag)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc(quote_len(*str) + 1, sizeof (char));
	if (!word)
		ft_error(MEMORY, bag);
	(*str)++;
	while (**str && !is_quote(**str))
	{
		word[i++] = **str;
		(*str)++;
	}
	(*str)++;
	word[i] = 0;
	return (word);
}

BOOL	is_quote(char c)
{
	if (c == '"' || c == '\'')
		return (TRUE);
	return (FALSE);
}

int	quote_len(char *str)
{
	char	c;
	int		i;

	c = str[0];
	i = 1;
	while (str[i] && str[i] != c)
		i++;
	return (i - 2);
}
