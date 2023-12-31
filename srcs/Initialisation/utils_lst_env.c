/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:44:03 by yidouiss          #+#    #+#             */
/*   Updated: 2023/11/23 21:44:03 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list_env	*ft_env_lstnew(t_parsing *bag, char *envstr)
{
	t_list_env	*new;

	new = ft_calloc(1, sizeof (t_list_env));
	if (!new)
		ft_error(MALLOC, bag);
	new->key = ft_key(envstr, bag);
	new->value = ft_value(envstr, bag);
	new->next = NULL;
	return (new);
}

char	*ft_key(char *str, t_parsing *bag)
{
	char	*retstr;
	int		i;

	i = 0;
	while (str[i] != '=')
		i++;
	retstr = ft_calloc(1, sizeof (char) * i + 1);
	if (!retstr)
		ft_error(MEMORY, bag);
	i = -1;
	while (str[++i] != '=')
		retstr[i] = str[i];
	retstr[i] = 0;
	return (retstr);
}

char	*ft_value(char *str, t_parsing *bag)
{
	char	*retstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '=')
		i++;
	while (str[j] != 0)
		j++;
	if (j - i == 1)
		return (NULL);
	retstr = ft_calloc(1, sizeof (char) * j - i);
	if (!retstr)
		ft_error(MEMORY, bag);
	i = 0;
	while (str[i] != '=')
		i++;
	j = 0;
	while (str[++i])
		retstr[j++] = str[i];
	return (retstr);
}

t_list_env	*ft_envp_lstlast(t_list_env *lst)
{
	t_list_env	*hook;

	hook = lst;
	while (hook->next)
		hook = hook->next;
	return (hook);
}

void	ft_lstadd_back_envp(t_parsing *bag, t_list_env *new)
{
	t_list_env	*tmp;

	if (bag->env_head)
	{
		tmp = ft_envp_lstlast(bag->env_head);
		tmp->next = new;
	}
	else
		bag->env_head = new;
}
