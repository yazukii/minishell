/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:01:51 by yidouiss          #+#    #+#             */
/*   Updated: 2023/11/23 18:01:51 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
void sigset(sigset_t *mySignalSet, t_parsing *bag) {
	struct sigaction new_action;

	new_action.sa_handler = sig_handler;
	sigemptyset(&new_action.sa_mask);
	new_action.sa_flags = 0;
	sigemptyset(mySignalSet);
	if (sigaddset(mySignalSet, SIGINT) || sigaddset(mySignalSet, SIGQUIT))
		ft_error(SIGNAL, bag);
	if (sigaction(SIGINT, &new_action, NULL) < 0)
		ft_error(SIGNAL, bag);
}*/


/*void sig_handler(int SIG)
utiliser la variable global;
void sig_handler(int SIG)
{
	if (SIG == SIGINT)
	{
		how the fuck to get the readline return
	}
	if (SIG == SIGQUIT)
	{
		ft_printf("\n%s", "exit");
		capté avec le readline?
	}
}*/