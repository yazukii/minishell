/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:08:52 by yidouiss          #+#    #+#             */
/*   Updated: 2023/07/26 17:59:56 by yidouiss         ###   ########.fr       */
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
			finput = ft_cmdsplit(input, ' ');
			while (i < ft_cmdnum(input, ' '))
			{
				printf("%s\n", finput[i]);
				i++;
			}
			free(finput);
			i = 0;
			//check_env(input);
			free(input);
		}
	}
	return (0);
}
