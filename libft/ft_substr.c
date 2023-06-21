/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:43:26 by yidouiss          #+#    #+#             */
/*   Updated: 2022/10/19 15:10:55 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*sub(char const *s, unsigned int start, size_t len, char *str)
{
	unsigned int	i;

	i = 0;
	while (i < len && s[start] && s[i])
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;

	if (!s)
		return (NULL);
	if (start > (size_t)ft_strlen(s))
	{
		str = (char *)malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len > (size_t)ft_strlen(s))
		str = (char *)malloc(sizeof(char) * ((ft_strlen(s)) + 1));
	else
		str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	return (sub(s, start, len, str));
}
