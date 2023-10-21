#include "minishell.h"


/*
 * Parseur:
 * 		En suivant les etapes decrites sur le schema on a:
 * 			- expand les keys / DONE
 * 			- split les elements
 */

void	parseur(t_parsing *bag)
{
	while (bag->input[bag->index])
	{
		if (state_quote(bag, bag->input[bag->index]) && check_env(bag))
			expand(bag);
		bag->index++;
	}
	pre_tokken(bag);
	pre_tokken_size(bag);
	tokkenizer(bag);
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