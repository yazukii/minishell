/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:41:34 by yidouiss          #+#    #+#             */
/*   Updated: 2023/08/24 17:49:25 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	checksquotes(char c, int i)
{
	static int	sq;

	if (i == -1)
	{
		if (sq == 1)
			return (1);
		sq = 0;
		return (0);
	}
	if (c == '\'' && sq == 1)
		sq = 0;
	else if (c == '\'' && sq == 0)
		sq = 1;
	return (sq);
}

int	ft_arr_size(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	ft_add(char ***arr, char *new, int index, int pos)
{
	int	size;
	int	i;
	int	j;
	char **str;

	i = 0;
	j = 0;
	size = ft_arr_size(*arr);
	str = malloc(sizeof(char*) * size + 1);
	while (i < size || j < size)
	{
		if (i == index)
		{
			str[j] = ft_strdup(new);
			j++;
		}
		else
			str[j] = ft_strdup(*arr[i]);
		i++;
		j++;
	}
	i = 0;
	*arr = str;
	//printf("%d\n", size);
	return (0);
}
