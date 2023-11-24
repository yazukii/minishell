/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <jmorcom-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:10:03 by jmorcom-          #+#    #+#             */
/*   Updated: 2022/10/19 16:34:08 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/libft.h"

void	*ft_memchr(const void *s, int c, int n)
{
	unsigned char	*p;
	int				i;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		if (p[i] == (unsigned char) c)
		{
			return (p + i);
		}
		i++;
	}
	return (0);
}
