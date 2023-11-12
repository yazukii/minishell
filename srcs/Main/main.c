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
<<<<<<< HEAD

t_status g_status;

=======
/*
>>>>>>> jmorcom-
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
}*/

char	*create_out(t_parsing *bag)
{
	char *out;

	getcwd(bag->cwd, 1024);
	out = ft_strjoin(RED, bag->cwd);
	out = ft_strjoin(out, BLU" | Minishell$ "RESET);
	return (out);
}

int	main(int argc, char **argv, char **envp)
{
    t_parsing	*bag;
//	sigset_t	*mySignalSet;

    (void) argv;
    (void) argc;
    bag = NULL;
	//mySignalSet = NULL;
	handle_signal(bag);
    rl_initialize();
	bag = init_parseur(bag, envp, TRUE);
//	sigset(mySignalSet, bag);
    while (1)
    {
		bag->input = readline("minishell$ ");
		bag->hook_input = bag->input;
		if (*bag->input)
        	input_handling(bag);
    }
	free_all(bag);
	free_env(bag);
    return (0);
}

void input_handling(t_parsing *bag)
{
	add_history(bag->input);
	parseur(bag);
//	printf("%d\n", bag->t_head->builtin_id);
//	printlist(*bag, 0);
	free_all(bag);
}