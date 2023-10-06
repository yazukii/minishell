/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <jmorcom-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:15:58 by jmorcom-          #+#    #+#             */
/*   Updated: 2022/10/26 15:59:06 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

void	hexa(char c, unsigned int arg, int *count);
int		hexastr(unsigned long int address);
int		decimal(int arg);
int		countargs(const char *string);
int		putstrarg(char *s);
char	*uitoa(unsigned int n);
int		dispatch(char c, va_list arg);
int		ft_printf(const char *input, ...);
int		udecimal(unsigned int arg);

#endif