/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:05:06 by yidouiss          #+#    #+#             */
/*   Updated: 2023/07/26 18:57:35 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_error(int ERRNUMBER, t_parsing *sac)
{
    (void)ERRNUMBER;
    (void)sac;
	if (errno == 1)
		printf(RED"Syntax error, you need to close the quotes\n"RESET);
	return (1);
}
