#include "../../headers/minishell.h"

// in pretokken check:
//					- check if you take the sep char in the string you split / DONE
//						- the char sep is put with the word before it
//						- if the char sep ==  > < | it needs its own tokkenizer
//						- if the char sep == \0 ' ' \"
void pre_tokken(t_parsing *bag, char *prompt)
{
	t_list_pre	*new;

	while(*prompt == ' ')
		prompt++;
	while (*prompt)
	{
		new = ft_pre_lstnew(get_pre_token(bag, &prompt), bag);
		ft_pre_lstadd_back(ft_pre_lstlast(bag->p_head), new, bag);
	}
}

char *get_pre_token(t_parsing *bag, char **str)
{
	char *word;

	word = NULL;
	if (**str == '>' || **str == '<' || **str == '|')
		word = get_redir(str, bag);
	else if (**str == '\'' || **str == '"')
		word = get_quote(str, bag);
	else if (**str == ' ')
	{
		(*str)++;
		word = get_pre_token(bag, str);
	}
	else if (**str != ' ')
		word = get_word(str, bag);
	return (word);
}
