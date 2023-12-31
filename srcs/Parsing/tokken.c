/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokken.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:44:03 by yidouiss          #+#    #+#             */
/*   Updated: 2023/11/26 15:32:01 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokkenizer(t_parsing *bag)
{
	bag->can_exp = TRUE;
	bag->in_double = FALSE;
	bag->in_simple = FALSE;
	fill_tokkens_recursive(bag);
	bag->first_cmd = TRUE;
}

void	fill_tokkens_recursive(t_parsing *bag)
{
	if (!(bag->p_head))
		return ;
	if (bag->first_cmd)
		ft_lstadd_back_token(NULL, ft_t_lstnew(bag), bag);
	r_fill_redir(bag);
	fill_cmd(bag);
	if (fill_pipe(bag) == FALSE)
		return ;
	if (bag->p_head)
		fill_tokkens_recursive(bag);
}

/* this function checks if the pipe syntax is correct
 * (not 2 pipes, not null after pipe)
 * If it is then the first pre_tokken should be a pipe
 * if it is then we delete the pipe pre_tokken and move on
 * */
BOOL	fill_pipe(t_parsing *bag)
{
	t_list_pre	*tmp;

	if (!bag->p_head || check_redir((bag->p_head)->pre_tokken) != PIPE)
		return (FALSE);
	if (check_redir((bag->p_head)->pre_tokken) == PIPE && \
	(!(bag->p_head)->next || \
	check_redir((bag->p_head)->next->pre_tokken) == PIPE))
		ft_error(SYNTAX, bag);
	tmp = bag->p_head;
	bag->p_head = (bag->p_head)->next;
	ft_t_lstlast(bag->t_head)->pipe_status = TRUE;
	free(tmp->pre_tokken);
	free(tmp);
	return (TRUE);
}

/* this function needs to fill the cmd tokken with the args fd
 * first arg is the cmd
 * the following are args*/
void	fill_cmd(t_parsing *bag)
{
	t_list_tokken	*last;

	if (bag->first_cmd == TRUE)
		bag->first_cmd = FALSE;
	else
		ft_lstadd_back_token(bag->t_head, ft_t_lstnew(bag), bag);
	last = ft_t_lstlast(bag->t_head);
	if (!(bag->p_head) || check_redir((bag->p_head)->pre_tokken) == PIPE)
		ft_error(SYNTAX, bag);
	last->cmd = ft_calloc(ft_strlen(bag->p_head->pre_tokken) + 1,\
	sizeof (char));
	ft_strlcpy(last->cmd, bag->p_head->pre_tokken, \
	ft_strlen(bag->p_head->pre_tokken) + 1);
	last->size = bag->p_head->size;
	free_p_args(bag);
	check_builtins(last, bag);
	while (bag->p_head && check_redir((bag->p_head)->pre_tokken) != PIPE)
	{
		ft_lstadd_back_arg(bag, \
		ft_a_lstnew(ft_strdup((bag->p_head)->pre_tokken), bag));
		free_p_args(bag);
	}
}
