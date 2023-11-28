/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:01:51 by yidouiss          #+#    #+#             */
/*   Updated: 2023/11/23 18:01:51 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_redir(char **str, t_parsing *bag)
{
	char	*word;
	int		check;

	check = check_redir(*str);
	if (check == APPEND || check == HEREDOC)
		word = ft_calloc(1, sizeof (char) * 3);
	if (check == INPUT || check == OUTPUT || check == PIPE)
		word = ft_calloc(1, sizeof (char) * 2);
	if (check == HEREDOC || check == APPEND)
		ft_strlcpy(word, *str, 3);
	else if (check == INPUT || check == OUTPUT || check == PIPE)
		ft_strlcpy(word, *str, 2);
	if (check == PIPE || check == INPUT || check == OUTPUT)
		(*str)++;
	if (check == APPEND || check == HEREDOC)
		(*str) = (*str) + 2;
	if (!word)
		ft_error(MEMORY, bag);
	return (word);
}

int	check_redir(char *str)
{
	if (str[0] == '<' && str[1] == '<')
		return (HEREDOC);
	if (str[0] == '>' && str[1] == '>')
		return (APPEND);
	if (str[0] == '<')
		return (INPUT);
	if (str[0] == '>')
		return (OUTPUT);
	if (str[0] == '|')
		return (PIPE);
	return (-1);
}
