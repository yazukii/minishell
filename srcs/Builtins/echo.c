/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:44:03 by yidouiss          #+#    #+#             */
/*   Updated: 2023/11/23 21:44:03 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int ft_echo(t_list_tokken *current)
{
   t_list_arg	*tmp;
   int 			n;

   n = 0;
   if (!(current)->a_head)
	   return (EXIT_FAILURE);
   tmp = (current)->a_head;
   if (!ft_strncmp(tmp->arg, "-n", 2))
   {
	   n = 1;
	   tmp = tmp->next;
   }
   while (tmp)
   {
	   printf("%s ", tmp->arg);
	   tmp = tmp->next;
   }
   if (n == 0)
	   printf("\n");
	return (EXIT_SUCCESS);
}