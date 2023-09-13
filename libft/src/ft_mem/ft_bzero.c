/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <jmorcom-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:40:04 by jmorcom-          #+#    #+#             */
/*   Updated: 2022/10/21 13:57:47 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_bzero(void *s, int n)
{
	unsigned char	*d;

	d = (unsigned char *) s;
	if (n == 0)
		return ;
	while (n > 0)
	{
		*d++ = '\0';
		n--;
	}
}
