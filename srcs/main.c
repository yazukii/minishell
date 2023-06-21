/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:08:52 by yidouiss          #+#    #+#             */
/*   Updated: 2023/06/13 18:06:07 by yidouiss         ###   ########.fr       */
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
		input = readline("minishell$ ");
		if (input)
		{
			add_history(input);
			printf("You entered: %s\n", input);
			if (ft_strcmp(input, "exit") == 0)
			{
				free(input);
				exit(0);
			}
			free(input);
		}
	}
	return (0);
}