#include "../../headers/minishell.h"

/*pour cd:
 * change the current dir
 * understanding in which dir you are
 * using ~ to represent the home dir
 * implement
 * implement -  to go directly to the last dir you were at (use oldpwd)
 * error management
 */

int cd(t_list_tokken tokken, t_parsing *bag)
{
    if (!tokken.a_head)
        chdir(getenv("HOME"));
    else
    {
        if (tokken.a_head->arg[0] != '/')
            tokken.a_head->arg = ft_strjoin("/", tokken.a_head->arg);
        if (chdir(ft_strjoin(bag->cwd, tokken.a_head->arg)) == -1)
            printf("This directory does not exist\n");
    }
    return (0);
}

