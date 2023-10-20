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
    if (!tokken.args)
        chdir(getenv("HOME"));
    else
    {
        if (tokken.args[0][0] != '/')
            tokken.args[0] = ft_strjoin("/", tokken.args[0]);
        if (chdir(ft_strjoin(bag->cwd, tokken.args[0])) == -1)
            printf("This directory does not exist\n");
    }
    return (0);
}