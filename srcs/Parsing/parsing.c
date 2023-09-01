/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:58:02 by yidouiss          #+#    #+#             */
/*   Updated: 2023/08/23 19:06:11 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	test(char **finput, char *input)
{
	int			i;

	i = 0;
	while (i < ft_cmdnum(input, ' '))
	{
		printf("%s\n", finput[i]);
		i++;
	}
	free(finput);
	return (0);
}

int parsing(char *input)
{
	int			i;
	char** finput;

	i = 0;
	finput = ft_cmdsplit(input, ' ');
	while (i < ft_cmdnum(input, ' '))
	{
		expand(&finput[i]);
		tilde(&finput[i]);
		i++;
	}
	cmdsub(&finput);
	if (finput == NULL)
		return (ft_error(1));
	test(finput, input);
	return(0);
}