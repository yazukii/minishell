/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:08:52 by yidouiss          #+#    #+#             */
/*   Updated: 2023/06/29 12:47:35 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static int    is_pipe(char *str)
{
    return (!ft_strncmp(str, "|", 1));
}

int	main(int argc, char **argv)
{
	char	*input;
	(void)argc;
	(void)argv;

	rl_initialize();
	while (1)
	{
		input = readline("\x1B[34mminishell$ ");
		if (input)
		{
			add_history(input);
			printf("%d\n", is_pipe(input));
			//printf("%d\n", splitargs(input));
			free(input);
		}
	}
	return (0);
}