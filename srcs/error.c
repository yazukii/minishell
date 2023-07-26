/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:05:06 by yidouiss          #+#    #+#             */
/*   Updated: 2023/07/26 18:36:28 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	ft_error(int e)
{
	if (e == 1)
	{
		printf(RED"Syntax error, you need to close the quotes\n"RESET);
		return (1);
	}
	exit(1);
}