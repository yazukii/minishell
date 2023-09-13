/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   udecimal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <jmorcom-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:29:25 by jmorcom-          #+#    #+#             */
/*   Updated: 2022/10/26 22:36:38 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/ft_printf.h"

int	udecimal(unsigned int arg)
{
	char	*str;
	int		len;
	int		count;

	str = uitoa(arg);
	len = ft_strlen(str);
	count = write(1, str, len);
	free (str);
	return (count);
}
