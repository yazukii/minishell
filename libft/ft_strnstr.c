/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:42:12 by yidouiss          #+#    #+#             */
/*   Updated: 2022/10/19 14:34:00 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hs, const char *ndl, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*ndl == '\0')
		return ((char *)hs);
	if (len == 0)
		return (NULL);
	if (hs == ndl)
		return ((char *)hs);
	while (i < len && *hs != '\0')
	{
		while (ndl[j] == hs[j] && (i + j) < len)
		{
			j++;
			if (j == (size_t)ft_strlen((char *)ndl))
				return ((char *)hs);
		}
		i++;
		hs++;
		j = 0;
	}
	return (NULL);
}
