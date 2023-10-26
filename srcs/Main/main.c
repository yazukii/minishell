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

void printlist(t_parsing bag, int st)
{
	t_list_tokken	*tokken = bag.t_head;
	t_list_arg		*arg = bag.t_head->a_head;

	if (st == 0)
	{
		while (tokken)
		{
			printf("builtin = %d\ncmd = %s\npipe status = %d\n", tokken->builtin_id, tokken->cmd, tokken->pipe_status);
			printlist(bag, 1);
			tokken = tokken->next;
		}
	}
	if (st == 1)
	{
		while (arg)
		{
			printf("%sarg = %s\noutput = %d\ninput = %d\nappend = %d\n%s", RED, arg->arg, arg->output, arg->input, arg->append, RESET);
			arg = arg->next;
		}
	}
}

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
		getcwd(bag->cwd, 1024);
		printf("%s%s | %s", RED,bag->cwd ,RESET);
		bag->input = readline(BLU"minishell$ "RESET);
		if (*bag->input)
        {
            add_history(bag->input);
            parseur(bag);
			choose_builtin(bag);
			//printlist(*bag, 0);
            free_all(bag);
        }
		bag = init_parseur(bag, envp, FALSE);
    }
	free_env(bag);
    return (0);
}

