/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:01:51 by yidouiss          #+#    #+#             */
/*   Updated: 2023/11/23 23:11:02 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_word(char **str, t_parsing *bag)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc(1, sizeof (char));
	if (!word)
		ft_error(MEMORY, bag);
	while (is_letter(**str))
	{
		word[i++] = **str;
		(*str)++;
	}
	word[i] = 0;
	return (word);
}

int	word_len(char *str)
{
	int	i;

	i = 0;
	while (is_letter(str[i]))
		i++;
	return (i);
}

BOOL	is_letter(char c)
{
	if (c == '>' || c == '<' || c == '|' || c == '\'' \
	|| c == '"' || c == ' ' || !c)
		return (FALSE);
	else
		return (TRUE);
}
