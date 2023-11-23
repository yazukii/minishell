#include "../../headers/minishell.h"

/*pour cd:
 * change the current dir
 * understanding in which dir you are
 * using ~ to represent the home dir
 * implement
 * implement -  to go directly to the last dir you were at (use oldpwd)
 * error management
 */

int cd(t_list_tokken *current, char *cwd)
{
    if (!(current)->a_head)
        chdir(getenv("HOME"));
    else
    {
        if ((current)->a_head->arg[0] != '/')
            (current)->a_head->arg = ft_strjoin("/", (current)->a_head->arg);
        if (chdir(ft_strjoin(cwd, (current)->a_head->arg)) == -1)
            printf("This directory does not exist\n");
    }
    return (0);
}

