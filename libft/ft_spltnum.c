/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spltnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:20:40 by yidouiss          #+#    #+#             */
/*   Updated: 2023/06/24 20:23:48 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_spltnum(char const *s, char c)
{
	int	sw;
	int	size;

	sw = 0;
	size = 0;
	while (*s)
	{
		if (*s != c && sw == 0)
		{
			sw = 1;
			size++;
		}
		else if (*s == c)
			sw = 0;
		s++;
	}
	return (size);
}
