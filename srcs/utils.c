/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:41:34 by yidouiss          #+#    #+#             */
/*   Updated: 2023/07/30 23:10:20 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

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
