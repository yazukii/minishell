/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <jmorcom-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:13:23 by jmorcom-          #+#    #+#             */
/*   Updated: 2022/10/19 14:29:49 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*to_string(char	*str, int c, int n)
{
	while (c >= 1 && n > 0)
	{
		str[c-- - 1] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}

int	count(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (0);
	if (n == 0)
		count++;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		c;

	c = count(n);
	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	str = malloc(sizeof(char) * (c + 1));
	if (!str)
		return (0);
	str[c] = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	if (n == 0)
		str[0] = '0';
	str = to_string(str, c, n);
	return (str);
}
