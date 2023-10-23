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
/*
void printlist(t_parsing *bag)
{
    while ((bag->t_head))
    {
        static int i;
        while(bag->)
            printf("%d\n", bag->t_head->output[i++]);
        i = 0;
        while(i <bag->t_head->input_nbr)
            printf("%d\n", bag->t_head->input[i++]);
        bag->t_head = bag->t_head->next;
    }
}*/

int	main(int argc, char **argv, char **envp)
{
    t_parsing	*bag;

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
//            printlist(bag);
            free_all(bag);
        }
		bag = init_parseur(bag, envp, TRUE);
    }
    return (0);
}

