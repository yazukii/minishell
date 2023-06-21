/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:41:10 by yidouiss          #+#    #+#             */
/*   Updated: 2022/10/19 15:18:53 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	getstart(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(set);
	while (j < len)
	{
		if (s1[i] == set[j])
		{
			i++;
			j = -1;
		}
		j++;
	}
	if (i == ft_strlen(s1))
		return (0);
	return (i);
}

int	getend(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	len;

	i = ft_strlen(s1) - 1;
	j = 0;
	len = ft_strlen(set);
	while (j < len)
	{
		if (s1[i] == set[j])
		{
			i--;
			j = -1;
		}
		j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;
	int		i;

	i = 0;
	start = getstart(s1, set);
	end = getend(s1, set) + 1;
	str = (char *)malloc(sizeof(char) * (end - start) + 1);
	if (!str || !s1 || !set)
		return (NULL);
	while (start < end)
	{
		str[i] = s1[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
