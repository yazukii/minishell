/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 23:26:03 by yidouiss          #+#    #+#             */
/*   Updated: 2023/11/23 23:42:03 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	parseur(t_parsing *bag)
{
	expand(bag);
	clean_end_space(bag);
	pre_tokken(bag, bag->input);
	pre_tokken_size(bag);
	tokkenizer(bag);
	get_option(bag);
	print_exec(bag->t_head);
	return (0);
}

void	print_exec(t_list_tokken *test)
{
	char	**test1;
	int		i;

	i = 0;
	test1 = test->exec;
	while (test1[i])
	{
		printf("%s\n", test1[i]);
		i++;
	}
}
