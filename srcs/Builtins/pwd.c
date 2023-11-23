#include "../../headers/minishell.h"

int ft_pwd(t_list_tokken *current, t_parsing *bag)
{
    if (current->a_head)
    {
        printf("Too many arguments\n");
        return (1);
    }
    printf("%s\n", bag->cwd);
    return (0);
}
