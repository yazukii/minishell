/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:08:52 by yidouiss          #+#    #+#             */
/*   Updated: 2023/06/24 21:07:37 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

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
			printf("%d\n", splitargs(input));
			free(input);
		}
	}
	return (0);
}
//bla