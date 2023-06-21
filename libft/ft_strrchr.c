/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:30:19 by yidouiss          #+#    #+#             */
/*   Updated: 2022/10/17 12:08:39 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*rtn;
	int		sw;

	sw = 0;
	while (*s)
	{
		if (*s == (char)c)
		{
			rtn = (char *)s;
			sw = 1;
		}
		s++;
	}
	if ((char)c == '\0' && *s == '\0')
		return ((char *)s);
	if (sw == 1)
		return (rtn);
	return (NULL);
}
