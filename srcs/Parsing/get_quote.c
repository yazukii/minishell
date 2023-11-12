#include "minishell.h"

char *get_quote(char **str, t_parsing *bag)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(sizeof (char) * quote_len(*str) + 1);
	if (!word)
		ft_error(MEMORY, bag);
	(*str)++;
	while (**str && !is_quote(**str))
	{
		word[i++] = **str;
		(*str)++;
	}
	(*str)++;
	word[i] = 0;
	return (word);
}

bool is_quote(char c)
{
	if (c == '"' || c == '\'')
		return (TRUE);
	return (FALSE);
}

int quote_len(char *str)
{
	char	c;
	int		i;

	c = str[0];
	i = 1;
	while (str[i] && str[i] != c)
		i++;
	return (i - 2);
}