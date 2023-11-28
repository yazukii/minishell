/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <jmorcom-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:29:52 by jmorcom-          #+#    #+#             */
/*   Updated: 2022/10/18 15:35:41 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/libft.h"

char	*ft_strdup(char *s1)
{
	int		i;
	char	*res;

	res = ft_calloc(ft_strlen(s1) + 1, sizeof (char));
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = 0;
	return (res);
}
