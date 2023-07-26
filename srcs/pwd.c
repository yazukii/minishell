/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:05:11 by yidouiss          #+#    #+#             */
/*   Updated: 2023/07/16 16:34:22 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	*pwd(int ret)
{
	char *pwd;

	pwd = getcwd(NULL, 32);
	printf("%s\n", pwd);
	if (ret == 1)
	{
		free (pwd);
		return(NULL);
	}
	else
		return (pwd);
}