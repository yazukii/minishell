/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:44:03 by yidouiss          #+#    #+#             */
/*   Updated: 2023/11/27 14:04:44 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

t_parsing	*init_parseur(t_parsing *bag, char **envp, int flag)
{
	if (flag == TRUE)
	{
		bag = ft_calloc(1, sizeof (t_parsing));
		if (!bag)
			ft_error(MALLOC, bag);
		init_envp(bag, envp);
		init_builtins(bag);
	}
	bag->cwd = ft_calloc(1, sizeof(char) * 1024);
	if (!bag->cwd)
		ft_error(MALLOC, bag);
	bag->index = 0;
	bag->input = NULL;
	bag->can_exp = TRUE;
	bag->in_double = FALSE;
	bag->in_simple = FALSE;
	bag->has_expanded = FALSE;
	bag->heredoc_flag = FALSE;
	bag->first_cmd = TRUE;
	bag->key = NULL;
	bag->p_head = NULL;
	bag->t_head = NULL;
	return (bag);
}

void	init_envp(t_parsing *bag, char **envp)
{
	int			i;
	t_list_env	*current;

	i = 0;
	while (envp[i] != NULL)
	{
		ft_lstadd_back_envp(bag, ft_env_lstnew(bag, envp[i]));
		i++;
	}
	if (!bag->env_head)
		perror("ERROR: ");
	current = bag->env_head;
	while (current)
	{
		(current)->k_size = ft_strlen((current)->key);
		(current)->v_size = ft_strlen((current)->value);
		(current) = (current)->next;
	}
}

void	init_builtins(t_parsing *bag)
{
	bag->builtins = ft_calloc(1, sizeof (char *) * 8);
	if (!bag->builtins)
		ft_error(MALLOC, bag);
	bag->builtins[0] = "echo";
	bag->builtins[1] = "cd";
	bag->builtins[2] = "pwd";
	bag->builtins[3] = "export";
	bag->builtins[4] = "unset";
	bag->builtins[5] = "ft_env";
	bag->builtins[6] = "exit";
	bag->builtins[7] = NULL;
}
