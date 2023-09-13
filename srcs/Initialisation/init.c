#include "minishell.h"

void	init_parseur(t_parsing *bag, char **envp)
{
	bag->index = 0;
	bag->input = NULL;
	bag->can_exp = 1;
	bag->in_double = 0;
	bag->in_simple = 0;
	bag->key = NULL;
	bag->key_size = 0;
	bag->value = NULL;
	bag->value_size = 0;
	bag->split_index = 0;
	bag->p_head = NULL;
	bag->split = NULL;
	bag->envp = envp;
	init_builtins(bag);
	init_cmds(bag);
}

void	init_builtins(t_parsing *bag)
{
	bag->builtins = malloc(sizeof (char *) * 8);
	bag->builtins[0] = "echo";
	bag->builtins[1] = "cd";
	bag->builtins[2] = "pwd";
	bag->builtins[3] = "export";
	bag->builtins[4] = "unset";
	bag->builtins[5] = "env";
	bag->builtins[6] = "exit";
	bag->builtins[7] = NULL;
}
