#include "../../headers/minishell.h"

/*void	changeout(t_list_tokken tokken)
{

}

void	changein(t_list_tokken tokken)
{

}

void	fd_redir(t_list_tokken tokken, t_parsing *bag)
{
	while ()
	if (tokken.input_nbr)
		changein(tokken);
	if (tokken.output_nbr)
		changeout(tokken);
	choose_builtin(tokken, bag);
}*/

void    choose_builtin(t_parsing *bag)
{
    switch (bag->t_head->builtin_id) {
		case (NO_BUILTIN):
			break;
        case (ECHO):
            echo(*bag);
            break;
        case (CD):
            cd(bag);
            break;
        case (PWD):
            pwd(bag);
            break;
        case (EXPORT):
			export(bag);
            break;
        case (UNSET):
			unset(*bag);
            break;
        case (ENV):
            env(*bag);
            break;
        case (EXIT):
            exit(0);
            break;
    }
}
