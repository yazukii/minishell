/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <jmorcom-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:16:14 by jmorcom-          #+#    #+#             */
/*   Updated: 2022/10/21 17:10:18 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>

char	*ft_strnstr(char *str, char *to_find, size_t len)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (to_find[0] == 0)
		return (str);
	while (str[j] && len)
	{
		while (str[j] != to_find[i] && str[j] && len--)
			j++;
		while (str[i + j] == to_find[i] && to_find[i] && str[i + j] && len--)
			i++;
		if (to_find[i] == 0 && len)
			return (str + j);
		if (str[j] && len--)
			j++;
		i = 0;
	}
	return (0);
}
