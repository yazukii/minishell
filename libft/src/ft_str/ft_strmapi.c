/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <jmorcom-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:33:26 by jmorcom-          #+#    #+#             */
/*   Updated: 2022/10/19 14:44:19 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*cpy;

	i = 0;
	if (!s)
		return (ft_strdup(""));
	if (!f)
		return ((char *)s);
	cpy = ft_strdup(s);
	if (!cpy)
		return (ft_strdup(""));
	while (s[i])
	{
		cpy[i] = (*f)(i, cpy[i]);
		i++;
	}
	return (cpy);
}
