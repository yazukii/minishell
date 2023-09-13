/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <jmorcom-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:49:46 by jmorcom-          #+#    #+#             */
/*   Updated: 2022/10/21 17:14:15 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*instance;

	instance = (t_list *) malloc(sizeof(t_list));
	if (!instance)
		exit(1);
	instance->index = *((int *)content);
	instance->next = NULL;
	return (instance);
}
