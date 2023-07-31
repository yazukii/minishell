/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:58:02 by yidouiss          #+#    #+#             */
/*   Updated: 2023/07/30 23:09:58 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	test(char **finput, char *input)
{
	int			i;

	i = 0;
	while (i < ft_cmdnum(input, ' '))
	{
		expand(&finput[i]);
		printf("%s\n", finput[i]);
		i++;
	}
	free(finput);
	return (0);
}

int parsing(char *input)
{
	char** finput;

	finput = ft_cmdsplit(input, ' ');
	if (finput == NULL)
		return (ft_error(1));
	test(finput, input);
	return(0);
}