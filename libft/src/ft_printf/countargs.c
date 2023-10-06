/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <jmorcom-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:00:25 by jmorcom-          #+#    #+#             */
/*   Updated: 2022/10/26 20:57:33 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/ft_printf.h"

int	countargs(const char *string)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (string[i])
	{
		if (string[i] == '%')
		{
			i += 2;
			count++;
		}
		else
			i++;
	}
	return (count);
}
