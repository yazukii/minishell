/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexastr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <jmorcom-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:56:09 by jmorcom-          #+#    #+#             */
/*   Updated: 2022/10/27 20:57:44 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/ft_printf.h"

#include<stdio.h>

void	ft_hexa(char c, unsigned long int arg, int *count);

int	hexastr(unsigned long int address)
{
	int				count;

	count = 0;
	count += write(1, "0x", 2);
	ft_hexa('x', address, &count);
	return (count);
}

int	ft_print2(int nmbr, char *str)
{
	return (write(1, &str[nmbr], 1));
}

void	ft_hexa(char c, unsigned long int arg, int *count)
{
	if (arg >= 16 && c == 'x')
	{
		ft_hexa(c, arg / 16, count);
		arg = arg % 16;
	}
	if (arg >= 16 && c == 'X')
	{
		ft_hexa(c, arg / 16, count);
		arg = arg % 16;
	}
	if (arg < 16 && c == 'x')
		*count += ft_print2((arg), "0123456789abcdef");
	if (arg < 16 && c == 'X')
		*count += ft_print2((arg), "0123456789ABCDEF");
}
