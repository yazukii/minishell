/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:01:51 by yidouiss          #+#    #+#             */
/*   Updated: 2023/11/23 18:01:51 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

PLACE_HOLDERS:"path_to_file"

int	redirection_left(PLACE_HOLDER:"path_to_file")
{
	int	fd;

	fd = open("path_to_file", O_RDONLY);
	if (fd == -1)
		perror();
	return (fd);
}
