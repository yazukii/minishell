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

int	main(int argc, char **argv, char **envp)
{
	t_parsing	*bag;
	t_list_pre	*current;

	(void) argv;
	(void) argc;
	bag = NULL;
	rl_initialize();
	bag = init_parseur(bag, envp, TRUE);
	while (1)
	{
		bag->input = readline(BLU"minishell$ "RESET);
		if (*bag->input)
		{
			add_history(bag->input);
			parseur(bag);
			current = ft_pre_lstlast(bag->p_head);
			printf("%s\n", current->pre_tokken);
			free(bag->input);
		}
		bag = init_parseur(bag, envp, FALSE);
	}
	return (0);
}
