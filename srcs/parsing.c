/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:58:02 by yidouiss          #+#    #+#             */
/*   Updated: 2023/07/17 20:44:36 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	command(t_args args)
{
	if (ft_strncmp(args.arg[0], "exit", 3) == 0)
		return (1);
	else if (ft_strncmp(args.arg[0], "echo", 4) == 0)
		return (2);
	else if (ft_strncmp(args.arg[0], "cd", 2) == 0)
		return (3);
	else if (ft_strncmp(args.arg[0], "pwd", 3) == 0)
		pwd(1);
	else if (ft_strncmp(args.arg[0], "export", 6) == 0)
		return (5);
	else if (ft_strncmp(args.arg[0], "unset", 5) == 0)
		return (6);
	else if (ft_strncmp(args.arg[0], "env", 3) == 0)
		return (7);
	return (0);
}

int	splitargs(char *input)
{
	t_args	args;
	int		i;

	i = 0;
	args.narg = ft_spltnum(input, ' ');
	args.arg = ft_split(input, ' ');
	command(args);
	return (0);
}

int sizestr(char *input)
{
	int i;

	i = 0;
	while (*input)
	{
		input++;
		i++;
	}
	return (i);
}

int	check_env(char *input)
{
	printf("%s\n", getenv(input));
	return (0);
}