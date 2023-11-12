#include "../../headers/minishell.h"

int pwd(t_parsing *bag)
{
    if ((bag->t_head)->a_head)
    {
        printf("Too many arguments\n");
        return (1);
    }
    printf("%s\n", bag->cwd);
    return (0);
}
