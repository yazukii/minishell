#include "minishell.h"

// in pretokken check:
//					- check if you take the sep char in the string you split / DONE
//						- the char sep is put with the word before it
//						- if the char sep ==  > < | it needs its own tokkenizer
//						- if the char sep == \0 ' ' \"
void	pre_tokken(t_parsing *sac)
{
	int	i;

	i = 1;
	sac->index = 0;
	*(sac->p_head) = malloc(sizeof (t_list_pre));
	while (sac->input[sac->index])
	{
		state_quote(sac, sac->input[sac->index]);
		if (pre_check_char(&(sac->input[sac->index])) == SPACE && sac->in_double)
			wait(&i);
		else if (pre_check_char(&(sac->input[sac->index])))
		{
			if (!id_pretokken(sac))
				ft_error(MEMORY, sac);
		}
		sac->index++;
	}
}

int	id_pretokken(t_parsing *sac)
{
	if (pre_check_char(&(sac->input[sac->index])) == SPACE)
		split_pretokken(sac, SPACE);
	else if (pre_check_char(&(sac->input[sac->index])) == ONECHAR)
		split_pretokken(sac, ONECHAR);
	else if (pre_check_char(&(sac->input[sac->index])) == TWOCHAR)
		split_pretokken(sac, TWOCHAR);
	if (!sac->split)
		return (FALSE);
	return (TRUE);
}

void	split_pretokken(t_parsing *sac, int flag)
{
	t_list_pre	*current;

	current = ft_pre_lstnew(tiny_split(sac));
	if (!current)
		ft_error(MEMORY, sac);
	ft_pre_lstadd_back(sac->p_head, current);
	if (flag == SPACE)
	{
		sac->split_index++;
		return ;
	}
	sac->index += flag - 1;
	current = ft_pre_lstnew(tiny_split(sac));
	if (!current)
		ft_error(MEMORY, sac);
	ft_pre_lstadd_back(sac->p_head, current);
}

int	pre_check_char(char const *c)
{
	if (*c == ' ' || !*c)
		return (SPACE);
	if (*c == '<' && *(c + 1) == '<')
		return (TWOCHAR);
	if (*c == '<' && *(c + 1) != '<')
		return (ONECHAR);
	if (*c == '>' && *(c + 1) == '>')
		return (TWOCHAR);
	if (*c == '>' && *(c + 1) != '>')
		return (ONECHAR);
	if (*c == '|')
		return (ONECHAR);
	return (CHAR);
}

char	*tiny_split(t_parsing *sac)
{
	char	*split;

	split = malloc(sizeof (char) * sac->index - sac->split_index + 1);
	if (!split)
		return (NULL);
	while (sac->split_index != sac->index)
	{
		sac->split[sac->split_index] = sac->input[sac->split_index];
		sac->split_index++;
	}
	sac->split[sac->split_index] = '\0';
	return (split);
}
