/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:02:37 by yidouiss          #+#    #+#             */
/*   Updated: 2023/08/22 11:23:22 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	*replace_tilde(char *str, int p, char *home)
{
	char	*tmp;
	int		i;
	int		j;
	int		h;

	i = 0;
	h = 0;
	j = 0;
	tmp = malloc(sizeof(char) * (ft_strlen(home) + ft_strlen(str)));
	while (j < ft_strlen(str))
	{
		if (i == p)
		{
			while (home[h])
				tmp[i++] = home[h++];
			j++;
		}
		tmp[i] = str[j];
		i++;
		j++;
	}
	return(tmp);
}

void	tilde(char **str)
{
	int		i;
	char	*home;
	char *tmp;

	i = 0;
	tmp = *str;
	home = getenv("HOME");
	while (tmp[i])
	{
		if (tmp[i] == '~')
		{
			tmp = replace_tilde(*str, i, home);
			i = i + ft_strlen(home);
		}
		i++;
	}
	*str = tmp;
}
