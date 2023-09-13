#include "minishell.h"

void	init_parseur(t_parsing *sac, char **envp)
{
	sac->index = 0;
	sac->input = NULL;
	sac->can_exp = 1;
	sac->in_double = 0;
	sac->in_simple = 0;
	sac->key = NULL;
	sac->key_size = 0;
	sac->value = NULL;
	sac->value_size = 0;
	sac->split_index = 0;
	sac->p_head = NULL;
	sac->split = NULL;
	init_builtins(sac);
	init_cmds(sac);
}

void	init_builtins(t_parsing *sac)
{
	sac->builtins = malloc(sizeof (char *) * 8);
	sac->builtins[0] = "echo";
	sac->builtins[1] = "cd";
	sac->builtins[2] = "pwd";
	sac->builtins[3] = "export";
	sac->builtins[4] = "unset";
	sac->builtins[5] = "env";
	sac->builtins[6] = "exit";
	sac->builtins[7] = NULL;
}

void	init_cmds(t_parsing *sac)
{
	sac->
}