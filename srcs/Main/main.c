/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:08:52 by yidouiss          #+#    #+#             */
/*   Updated: 2023/11/24 12:27:59 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

volatile sig_atomic_t	g_status;

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
	(void)argc;
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
	execution(bag, envp);
	free_all(bag);
}
