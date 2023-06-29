/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:58:02 by yidouiss          #+#    #+#             */
/*   Updated: 2023/06/29 12:45:54 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	convert(char *string, int s, int e)
{
	printf("quote detected from %d to %d\n", s, e);
	return(0);
}

int	check_quote(t_args args)
{
	int	i;
	int	s;
	int	e;
	int	flag;

	i = 0;
	s = 0;
	e = 0;
	flag = 0;
	while(i < args.narg)
	{
		while(*args.arg[i])
		{
			if (*args.arg[i] == "'" && flag == 0)
				flag = 1;
			if (*args.arg[i] == "'" && flag == 1)
			{
				convert(&args.arg[i], s, e);
				e = 0;
				s = 0;
				flag = 0;
			}
			*args.arg[i]++;
			if (flag == 0)
				s++;
			e++;
		}
	}
}

int	command(t_args args)
{
	printf("%s\n", args.arg[0]);
	if (ft_strncmp(args.arg[0], "exit", 3) == 0)
		return (1);
	else if (ft_strncmp(args.arg[0], "echo", 4) == 0)
		return (2);
	else if (ft_strncmp(args.arg[0], "cd", 2) == 0)
		return (3);
	else if (ft_strncmp(args.arg[0], "pwd", 3) == 0)
		return (4);
	else if (ft_strncmp(args.arg[0], "export", 6) == 0)
		return (5);
	else if (ft_strncmp(args.arg[0], "unset", 5) == 0)
		return (6);
	else if (ft_strncmp(args.arg[0], "env", 3) == 0)
		return (7);
	else
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

