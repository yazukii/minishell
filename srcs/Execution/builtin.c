#include "../../headers/minishell.h"

void    choose_builtin(t_parsing *bag)
{
    switch (bag->t_head->builtin_id) {
		case (NO_BUILTIN):
			exec_cmd(bag);
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
			free_all(bag);
			free_env(bag);
            exit(0);
            break;
    }
}
