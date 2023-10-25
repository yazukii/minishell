#include "minishell.h"


/*
 * Parseur:
 * 		En suivant les etapes decrites sur le schema on a:
 * 			- expand les keys / DONE
 * 			- split les elements
 */

int	parseur(t_parsing *bag)
{
	while (bag->input[bag->index])
	{
		if (state_quote(bag, bag->input[bag->index]))
        {
            if (check_env(bag))
                expand(bag);
        }
        bag->index++;
	}
	clean_end_space(bag);
	pre_tokken(bag);
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
	clean_single_quote(bag);
	clean_double_quote(bag);
	fill_tokken(bag);
}

