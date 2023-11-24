/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:44:03 by yidouiss          #+#    #+#             */
/*   Updated: 2023/11/23 21:44:03 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_freesplit(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
		free (paths[i++]);
	free(paths);
}

void	ft_strcat(char *dst, const char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
}

void	ft_strcpy(char *dst, const char *src)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(src);
	while (len--)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

char	**ft_getsplitedpath(t_list_env *head)
{
	char	*unsplited_path;
	char	**splited_path;

	unsplited_path = ft_getenv(head, "PATH");
	if (unsplited_path[0] == '\0')
	{
		free(unsplited_path);
		return (NULL);
	}
	splited_path = ft_split(unsplited_path);
	return (splited_path);
}

char	*ft_getenv(t_list_env *head, char *key)
{
	t_list_env	*tmp;

	tmp = head;
	while (!ft_strcmp(tmp->key, key, 4))
		tmp = tmp->next;
	return (ft_strdup(tmp->value));
}
