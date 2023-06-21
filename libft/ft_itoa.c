/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:21:56 by yidouiss          #+#    #+#             */
/*   Updated: 2022/10/26 15:48:48 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_int(int size, unsigned int num, char *str)
{
	while (num > 0)
	{
		str[size] = (num % 10) + 48;
		size--;
		num = num / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int				size;
	char			*str;
	unsigned int	num;

	size = ft_intlen(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	size--;
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		num = n * -1;
		str[0] = '-';
	}
	else
		num = n;
	str = ft_int(size, num, str);
	return (str);
}
