/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:12:45 by yidouiss          #+#    #+#             */
/*   Updated: 2022/10/19 12:23:54 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		lens1;
	int		lens2;
	int		i;
	int		j;

	lens1 = ft_strlen((char *)s1);
	lens2 = ft_strlen((char *)s2);
	i = 0;
	j = 0;
	str = (char *)malloc((sizeof(char) * lens1) + (sizeof(char) * lens2) + 1);
	if (!str)
		return (NULL);
	while (i++ < lens1)
		str[j++] = *s1++;
	i = 0;
	while (i++ < lens2)
		str[j++] = *s2++;
	str[j] = '\0';
	return (str);
}
