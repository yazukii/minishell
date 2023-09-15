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
            if (check_env(bag) == ERR)
                return (1);
            else if (check_env(bag))
                if (expand(bag) == ERR)
                    return (1);
        }
        bag->index++;
	}
	pre_tokken(bag);
	pre_tokken_size(bag);
    return (0);
	//tokkenizer(bag);
}
