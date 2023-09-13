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

#include"libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*strdup;

	len = ft_strlen(s1) + 1;
	strdup = malloc(sizeof(char) * len);
	if (!strdup)
		return (0);
	strdup = ft_memcpy(strdup, s1, len);
	return (strdup);
}
