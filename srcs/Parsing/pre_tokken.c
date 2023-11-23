/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_tokken.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:01:51 by yidouiss          #+#    #+#             */
/*   Updated: 2023/11/23 23:12:06 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	pre_tokken(t_parsing *bag, char *prompt)
{
	t_list_pre	*new;

	while (*prompt == ' ')
		prompt++;
	while (*prompt)
	{
		new = ft_pre_lstnew(get_pre_token(bag, &prompt), bag);
		ft_pre_lstadd_back(ft_pre_lstlast(bag->p_head), new, bag);
	}
}

char	*get_pre_token(t_parsing *bag, char **str)
{
	char	*word;

	word = NULL;
	if (**str == '>' || **str == '<' || **str == '|')
		word = get_redir(str, bag);
	else if (**str == '\'' || **str == '"')
		word = get_quote(str, bag);
	else if (**str == ' ')
	{
		(*str)++;
		word = get_pre_token(bag, str);
	}
	else if (**str != ' ')
		word = get_word(str, bag);
	return (word);
}
