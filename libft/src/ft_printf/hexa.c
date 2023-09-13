/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <jmorcom-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 00:38:57 by jmorcom-          #+#    #+#             */
/*   Updated: 2022/10/27 20:53:52 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/ft_printf.h"
#include<stdio.h>

int	ft_print(int nmbr, char *str)
{
	return (write(1, &str[nmbr], 1));
}

void	hexa(char c, unsigned int arg, int *count)
{
	if (arg >= 16 && c == 'x')
	{
		hexa(c, arg / 16, count);
		arg = arg % 16;
	}
	if (arg >= 16 && c == 'X')
	{
		hexa(c, arg / 16, count);
		arg = arg % 16;
	}
	if (arg < 16 && c == 'x')
		*count += ft_print((arg), "0123456789abcdef");
	if (arg < 16 && c == 'X')
		*count += ft_print((arg), "0123456789ABCDEF");
}
