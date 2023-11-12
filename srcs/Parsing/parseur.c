#include "minishell.h"


/*
 * Parsing:
 * - 4
 */

int	parseur(t_parsing *bag)
{
	expand(bag);
	clean_end_space(bag);
	pre_tokken(bag, bag->input);
	pre_tokken_size(bag);
	tokkenizer(bag);
    return (0);
}

void clean_end_space(t_parsing *bag)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (bag->input[i])
	{
		i++;
		j++;
	}
	i--;
	while (bag->input[i] == ' ')
		i--;
	if (i + 1 == j)
		return ;
	tmp = malloc(sizeof (char) * i + 2);
	if (!tmp)
		ft_error(MEMORY, bag);
	ft_strlcpy(tmp, bag->input, i + 2);
	free(bag->input);
	bag->input = tmp;
}

void	tokkenizer(t_parsing *bag)
{
	bag->can_exp = TRUE;
	bag->in_double = FALSE;
	bag->in_simple = FALSE;
	bag->t_head = malloc(sizeof (t_list_tokken **));
	(*bag->t_head) = ft_t_lstnew(bag);
	fill_tokkens_recursive(bag);
	//clean_in_out_put(bag);
}

