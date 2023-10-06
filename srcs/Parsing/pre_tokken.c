#include "../../headers/minishell.h"

// in pretokken check:
//					- check if you take the sep char in the string you split / DONE
//						- the char sep is put with the word before it
//						- if the char sep ==  > < | it needs its own tokkenizer
//						- if the char sep == \0 ' ' \"
void	pre_tokken(t_parsing *bag)
{
	int	i;

	i = 1;
	bag->index = 0;
	while (bag->input[bag->index])
	{
		state_quote(bag, bag->input[bag->index]);
		if (pre_check_char(&(bag->input[bag->index])) == SPACESEP && bag->in_double)
			wait(&i);
		else if (pre_check_char(&(bag->input[bag->index])))
		{
			if (!id_pretokken(bag))
				ft_error(MEMORY, bag);
		}
		bag->index++;
		if (pre_check_char(&(bag->input[bag->index])) == BACKSLASH)
		{
			if (!id_pretokken(bag))
				ft_error(MEMORY, bag);
		}
	}
}

int	id_pretokken(t_parsing *bag)
{
	if (pre_check_char(&(bag->input[bag->index])) == SPACESEP || \
			pre_check_char(&(bag->input[bag->index])) == BACKSLASH)
		split_pretokken(bag, SPACESEP);
	else if (pre_check_char(&(bag->input[bag->index])) == ONECHAR)
		split_pretokken(bag, ONECHAR);
	else if (pre_check_char(&(bag->input[bag->index])) == TWOCHAR)
		split_pretokken(bag, TWOCHAR);
	if (!bag->split)
		return (FALSE);
	return (TRUE);
}

void	split_pretokken(t_parsing *bag, int flag)
{
	t_list_pre	*current;

	current = ft_pre_lstnew(tiny_split(bag));
	if (!current)
		ft_error(MEMORY, bag);
	ft_pre_lstadd_back(&(bag->p_head), current);
	if (flag == SPACESEP)
	{
		bag->split_index++;
		return ;
	}
	bag->index += flag - 1;
	current = ft_pre_lstnew(tiny_split(bag));
	if (!current)
		ft_error(MEMORY, bag);
	ft_pre_lstadd_back(&(bag->p_head), current);
}

int	pre_check_char(char const *c)
{
	if (*c == ' ')
		return (SPACESEP);
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
	if (!*c)
		return (BACKSLASH);
	return (CHAR);
}

char	*tiny_split(t_parsing *bag)
{
	int	local_index;

	local_index = 0;
	bag->split = malloc(sizeof (char) * bag->index - bag->split_index + 1);
	if (!bag->split)
		return (NULL);
	while (bag->split_index != bag->index && bag->input[bag->split_index])
	{
		bag->split[local_index] = bag->input[bag->split_index];
		local_index++;
		bag->split_index++;
	}
	bag->split[bag->split_index] = '\0';
	return (bag->split);
}
