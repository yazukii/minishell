/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdsub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:45:58 by yidouiss          #+#    #+#             */
/*   Updated: 2023/08/24 15:17:42 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	ft_redir()
{
	printf("redir\n");
	return (0);
}

int	ft_pip(char ***tmp, int pos, int arr)
{
	if (ft_strlen(*tmp[arr]) < 2)
		return (0);
	ft_add(tmp, "|", pos, 1);
	printf("pip\n");
	return (0);
}

int	cmdsub(char ***str)
{
	char **tmp;
	int i;

	tmp = *str;
	i = 0;
	while (tmp[i])
	{
		if (tmp[i][0] == '<' || tmp[i][0] == '>')
			ft_redir();
		if (tmp[i][ft_strlen(tmp[i]) - 1] == '<')
			ft_redir();
		if (tmp[i][ft_strlen(tmp[i]) - 1] == '>')
			ft_redir();
		if (tmp[i][0] == '|')
			ft_pip(&tmp, 0, i);
		if (tmp[i][ft_strlen(tmp[i]) - 1] == '|')
			ft_pip(&tmp, 1, i);
		i++;
	}
	return (0);
}