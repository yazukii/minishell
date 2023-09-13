/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <jmorcom-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:36:43 by jmorcom-          #+#    #+#             */
/*   Updated: 2022/10/21 16:30:11 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set++ == c)
			return (0);
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	int			end;
	char		*trimmed;
	char		*rtn;

	start = 0;
	end = ft_strlen(s1);
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (!is_in_set(s1[start], set))
		start++;
	if (start == ft_strlen(s1))
	{
		rtn = ft_strdup("");
		return (rtn);
	}
	while (!is_in_set(s1[end - 1], set))
		end--;
	trimmed = ft_substr(s1, start, (end - start));
	return (trimmed);
}
