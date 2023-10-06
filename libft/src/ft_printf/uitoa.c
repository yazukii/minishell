/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uitoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <jmorcom-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:20:03 by jmorcom-          #+#    #+#             */
/*   Updated: 2022/10/26 22:40:00 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/ft_printf.h"

static char	*to_string(char	*str, int c, unsigned int n)
{
	while (c >= 1 && n > 0)
	{
		str[c-- - 1] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}

static int	count(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*uitoa(unsigned int n)
{
	char	*str;
	int		c;

	c = count(n);
	str = malloc(sizeof(char) * (c + 1));
	if (!str)
		return (0);
	str[c] = 0;
	if (n == 0)
		str[0] = '0';
	str = to_string(str, c, n);
	return (str);
}
