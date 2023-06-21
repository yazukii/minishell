/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:44:06 by yidouiss          #+#    #+#             */
/*   Updated: 2022/10/14 16:31:24 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*origin;
	char			*source;
	unsigned int	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	origin = dst;
	source = (char *)src;
	while (i < n)
	{
		origin[i] = source[i];
		i++;
	}
	return (dst);
}
