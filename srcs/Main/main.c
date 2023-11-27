/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:08:52 by yidouiss          #+#    #+#             */
/*   Updated: 2023/11/26 15:34:06 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

volatile sig_atomic_t	g_status;

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
			for (int j = 0; tokken->exec[j]; j++)
			{
				printf("%s\n", tokken->exec[j]);
			}
			tokken = tokken->next;
		}
	}
	if (st == 1)
	{
		while (arg)
		{
			printf("%sarg = %s\n%s", RED, arg->arg, RESET);
			arg = arg->next;
		}
	}
}

char	*create_out(t_parsing *bag)
{
	char	*out;

	getcwd(bag->cwd, 1024);
	out = ft_strjoin(RED, bag->cwd);
	out = ft_strjoin(out, BLU" | Minishell$ "RESET);
	return (out);
}

int	main(int argc, char **argv, char **envp)
{
	t_parsing	*bag;

	(void)argv;
	if (argc > 1)
			ft_error(ARGS, NULL);
	bag = NULL;
	handle_signal();
	rl_initialize();
	g_status = EXIT_SUCCESS;
	bag = init_parseur(bag, envp, TRUE);
	while (1)
	{
		bag->input = readline(create_out(bag));
		if (!bag->input)
			break ;
		bag->hook_input = bag->input;
		if (*bag->input)
			input_handling(bag, envp);
	}
	free_all(bag);
	free_env(bag);
	return (0);
}

void	input_handling(t_parsing *bag, char **envp)
{
	add_history(bag->input);
	parseur(bag);
	//printlist(*bag, 0);
	execution(bag, envp);
	free_all(bag);
}
