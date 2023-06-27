/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:00:08 by yidouiss          #+#    #+#             */
/*   Updated: 2023/06/24 20:25:46 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	str = malloc((ft_spltnum(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (i < ft_spltnum(s, c))
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
	return (idk(ft_spltnum(s, c), (char *)s, str, c));
}
