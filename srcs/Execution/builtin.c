#include "../../headers/minishell.h"

void choose_builtin(t_list_tokken *current, t_parsing *bag)
{
    switch (current->builtin_id) {
		case (NO_BUILTIN):
			process_management(current);
			break;
        case (ECHO):
            echo(current);
            break;
        case (CD):
            cd(current, bag->cwd);
            break;
        case (PWD):
			pwd(current, bag);
            break;
        case (EXPORT):
			export(current, bag);
            break;
        case (UNSET):
			unset(bag, current);
            break;
        case (ENV):
            env(bag);
            break;
        case (EXIT):
			free_all(bag);
			free_env(bag);
            exit(0);
            break;
    }
}
