/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:08:52 by yidouiss          #+#    #+#             */
/*   Updated: 2023/08/27 19:36:26 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//static int	is_pipe(char *str)
//{
//	return (!ft_strncmp(str, "|", 1));
//}

int	main(int argc, char **argv)
{
	char	*input;
	char	**finput;

	(void) argv;
	(void) argc;
	(void) finput;
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
