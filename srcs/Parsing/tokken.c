#include "minishell.h"

void	  fill_tokkens_recursive(t_parsing *bag)
{
	if (!(*bag->p_head))
		return ;
	r_fill_redir(bag);
	fill_cmd(bag);
	if (fill_pipe(bag) == FALSE)
		return ;
	if (*bag->p_head)
		fill_tokkens_recursive(bag);
}

/* this function checks if the pipe syntax is correct (not 2 pipes, not null after pipe)
 * If it is then the first pre_tokken should be a pipe
 * if it is then we delete the pipe pre_tokken and move on
 * */
bool fill_pipe(t_parsing *bag)
{
	t_list_pre	*tmp;

	if (!*bag->p_head || check_redir((*bag->p_head)->pre_tokken) != PIPE)
		return (FALSE);
	if (check_redir((*bag->p_head)->pre_tokken) == PIPE && (!(*bag->p_head)->next || check_redir((*bag->p_head)->next->pre_tokken) == PIPE ))
		ft_error(SYNTAX,bag);
	tmp = *bag->p_head;
	*bag->p_head = (*bag->p_head)->next;
	ft_t_lstlast(*bag->t_head)->pipe_status = TRUE;
	free(tmp->pre_tokken);
	free(tmp);
	return (TRUE);
}


/* this function needs to fill the cmd tokken with the args fd
 * first arg is the cmd
 * the following are args*/
void 	fill_cmd(t_parsing *bag)
{
	(void)bag;
	char *str=malloc(42);
	(void)str;
/*	if (bag->first_cmd == TRUE)
		bag->first_cmd = FALSE;
	else
		ft_lstadd_back_token(bag, ft_t_lstnew(bag));
	if (!*bag->p_head || check_redir((*bag->p_head)->pre_tokken) == PIPE)
		ft_error(SYNTAX, bag);*/
	//ft_t_lstlast(*bag->t_head)->cmd = malloc(sizeof (char) * (ft_strlen((*bag->p_head)->pre_tokken) + 1));
/*	ft_t_lstlast(*bag->t_head)->cmd = malloc(5);
	ft_strlcpy((*bag->p_head)->pre_tokken, ft_t_lstlast(*bag->t_head)->cmd, ft_strlen((*bag->p_head)->pre_tokken) + 1);
	free_p_args(bag);
	while ((*bag->p_head) && check_redir((*bag->p_head)->pre_tokken) != PIPE)
	{
		ft_lstadd_back_arg(bag, ft_a_lstnew(ft_strdup((*bag->p_head)->pre_tokken), bag));
		free_p_args(bag);
	}*/
}