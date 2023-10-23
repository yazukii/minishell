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

void printlist(t_list_tokken tk, t_list_arg ar, int st)
{
	t_list_tokken	tokken = tk;
	t_list_arg		arg = ar;
	if (st == 0)
	{
		while (tokken.cmd)
		{
			printf("builtin = %d\ncmd = %s\npipe status = %d\n", tokken.builtin_id, tokken.cmd, tokken.pipe_status);
			printlist(tokken, arg, 1);
			if (!tokken.next)
				break;
			tokken = *tokken.next;
		}
	}
	if (st == 1)
	{
		while (arg.arg)
		{
			printf("%sarg = %s\noutput = %d\ninput = %d\nappend = %d\n%s", RED, arg.arg, arg.output, arg.input, arg.append, RESET);
			if (!arg.next)
				break;
			arg = *arg.next;
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
		bag->input = readline(BLU"minishell$ "RESET);
		if (*bag->input)
        {
            add_history(bag->input);
            parseur(bag);
			printlist(*bag->t_head, *bag->t_head->a_head, 0);
            free_all(bag);
        }
		bag = init_parseur(bag, envp, TRUE);
    }
    return (0);
}

