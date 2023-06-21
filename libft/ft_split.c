/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:00:08 by yidouiss          #+#    #+#             */
/*   Updated: 2022/10/18 14:43:03 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	spltnum(char const *s, char c)
{
	int	sw;
	int	size;

	sw = 0;
	size = 0;
	while (*s)
	{
		if (*s != c && sw == 0)
		{
			sw = 1;
			size++;
		}
		else if (*s == c)
			sw = 0;
		s++;
	}
	return (size);
}

char	**idk(int size, char *s, char **str, char c)
{
	int	i;
	int	k;
	int	j;

	j = 0;
	i = 0;
	k = 0;
	while (i < size)
	{
		while (s[k] != c && s[k] != '\0')
		{
			str[i][j] = s[k];
			j++;
			k++;
		}
		if (j != 0)
		{
			str[i][j] = '\0';
			i++;
		}
		k++;
		j = 0;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**str;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	str = malloc((spltnum(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (i < spltnum(s, c))
	{
		while (s[k] != c && s[k] != '\0')
		{
			j++;
			k++;
		}
		if (j != 0)
			str[i++] = (char *)malloc(sizeof(char) * (j + 1));
		k++;
		j = 0;
	}
	str[i] = 0;
	return (idk(spltnum(s, c), (char *)s, str, c));
}
