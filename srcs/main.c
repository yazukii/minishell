/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:08:52 by yidouiss          #+#    #+#             */
/*   Updated: 2023/07/31 12:11:24 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static int	is_pipe(char *str)
{
	return (!ft_strncmp(str, "|", 1));
}

int	main(int argc, char **argv)
{
	char	*input;
	(void)argc;
	char **finput;
	int i = 0;
	(void)argv;

	//system("clear");
	//system("./badapple.sh");
	system("clear");
	system("./fumo.sh");
	rl_initialize();
	while (1)
	{
		input = readline(BLU"minishell$ "RESET);
		if (input)
		{
			add_history(input);
			//expand(input);
			parsing(input);
			free(input);
		}
	}
	return (0);
}
