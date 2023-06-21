/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:49:44 by yidouiss          #+#    #+#             */
/*   Updated: 2022/12/22 18:26:16 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

double	loop(char *arr, int i, int j, int flag)
{
	double	val;

	val = 0;
	while (arr[i] != '\0')
	{
		if (arr[i] != '.')
		{
			val = (val * 10) + (arr[i] - '0');
			if (flag == 1)
				j--;
		}
		if (arr[i] == '.')
		{
			if (flag == 1)
				return (0);
			flag = 1;
		}
		i++;
	}
	val = val * pow(10, j);
	return (val);
}

double	ft_stod(char *arr)
{
	int		i;
	int		j;
	int		flag;
	double	val;

	i = 0;
	j = 0;
	val = 0;
	flag = 0;
	if (arr[0] == '-')
		i++;
	val = loop(arr, i, j, flag);
	val = val * pow(10, j);
	if (arr[0] == '-')
		val = -val;
	return (val);
}
