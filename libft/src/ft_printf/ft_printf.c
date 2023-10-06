/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <jmorcom-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:44:21 by jmorcom-          #+#    #+#             */
/*   Updated: 2022/10/26 21:05:58 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/ft_printf.h"
#include "stdio.h"

int	ft_printf(const	char *string, ...)
{
	int		count;
	int		i;
	va_list	arg;

	i = 0;
	count = 0;
	va_start(arg, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			i++;
			count += dispatch(string[i++], arg);
		}
		else
			count += ft_putchar(string[i++]);
	}
	return (count);
}
