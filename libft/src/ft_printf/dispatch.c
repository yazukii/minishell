/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <jmorcom-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:26:31 by jmorcom-          #+#    #+#             */
/*   Updated: 2022/10/27 20:54:37 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/ft_printf.h"

int	dispatch(char c, va_list arg)
{
	int	count;

	count = 0;
	if (c == 'x' || c == 'X')
	{
		hexa(c, va_arg(arg, unsigned int), &count);
		return (count);
	}
	if (c == 'd' || c == 'i')
		return (decimal(va_arg(arg, int)));
	if (c == 'u')
		return (udecimal(va_arg(arg, unsigned int)));
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (c == '%')
		return (write(1, "%", 1));
	if (c == 's')
		return (putstrarg(va_arg(arg, char *)));
	if (c == 'p')
		return (hexastr(va_arg(arg, unsigned long int)));
	return (0);
}

	//%p hard write(1, "0x", 2) then transform the string into hexa.