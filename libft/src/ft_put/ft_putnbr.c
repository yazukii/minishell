/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <jmorcom-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:43:44 by jmorcom-          #+#    #+#             */
/*   Updated: 2022/10/25 16:54:10 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_putnbr(int n)
{
	char	c;
	int		count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else
	{
		if (n < 0)
		{
			count += write(1, "-", 1);
			ft_putnbr(-n);
		}
		else if (n < 10)
			c = n + 48;
		else if (n > 9)
		{
			ft_putnbr(n / 10);
			c = (n % 10) + '0';
		}
		count += write(1, &c, 1);
		return (count);
	}
}
