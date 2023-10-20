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

void printlist(t_parsing bag)
{
    printf("%s\n", bag.p_head->pre_tokken);
    while (bag.p_head->next)
    {
        bag.p_head = bag.p_head->next;
        printf("%s\n", bag.p_head->pre_tokken);
    }
}

void    test(t_parsing *bag)
{
    t_list_tokken tokken;
    tokken.type = BUILTINS;
    tokken.builtin_id = ENV;
    tokken.redir_id = PIPE;
    tokken.cmd = "cd";
    tokken.arg = "";
    tokken.args = NULL;/*
    tokken.args[0] = "test";
    tokken.args[1] = "test2";
    tokken.args[2] = NULL;
    tokken.output = 0;
    tokken.input = 1;*/
    choose_builtin(tokken, bag);
}

int	main(int argc, char **argv, char **envp)
{
    t_parsing	*bag;

    (void) argv;
    (void) argc;
    bag = NULL;
    rl_initialize();
    bag = init_parseur(bag, envp, TRUE);
	system("clear");
    while (1)
    {
        printf("%s%s | %s", RED, bag->cwd, RESET);
        bag->input = readline(BLU"minishell$ "RESET);
        if (*bag->input)
        {
            add_history(bag->input);
            test(bag);
            //parseur(bag);
            //printlist(*bag);
            //free(bag->input);
        }
        bag = init_parseur(bag, envp, FALSE);
    }
    return (0);
}