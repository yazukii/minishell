/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:57:41 by yidouiss          #+#    #+#             */
/*   Updated: 2022/10/14 16:49:38 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*origin;
	char			*source;
	unsigned int	i;

	i = 0;
	origin = dst;
	source = (char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (origin > source)
		while (len-- > 0)
			origin[len] = source[len];
	else
	{
		while (i < len)
		{
			origin[i] = source[i];
			i++;
		}
	}
	return (dst);
}
