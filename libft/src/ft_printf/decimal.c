/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <jmorcom-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 23:43:36 by jmorcom-          #+#    #+#             */
/*   Updated: 2022/10/26 22:36:08 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/ft_printf.h"

int	decimal(int arg)
{
	char	*str;
	int		len;
	int		count;

	str = ft_itoa(arg);
	len = ft_strlen(str);
	count = write(1, str, len);
	free (str);
	return (count);
}

//on doit free le itoa?