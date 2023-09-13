/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <jmorcom-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:08:37 by jmorcom-          #+#    #+#             */
/*   Updated: 2022/10/19 16:27:46 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ori;
	unsigned char	*des;
	size_t			i;

	i = 0;
	des = (unsigned char *) dst;
	ori = (unsigned char *) src;
	if (!src && !dst)
		return (0);
	if (des < ori)
	{
		while (i < len)
		{
			des[i] = ori[i];
			i++;
		}
	}
	else
	{
		while (len--)
			des[len] = ori[len];
	}
	return (dst);
}
