#include "../../headers/minishell.h"

t_parsing	*init_parseur(t_parsing *bag, char **envp, int flag)
{
	if (flag == TRUE)
	{
		bag = malloc(sizeof (t_parsing) * 1);
		init_envp(bag, envp);
		init_builtins(bag);
	}
	if (!bag)
		ft_error(MEMORY, NULL);
	bag->cwd = malloc(sizeof(char) * 1024);
	bag->index = 0;
	bag->input = NULL;
	bag->can_exp = TRUE;
	bag->in_double = FALSE;
	bag->in_simple = FALSE;
	bag->key = NULL;
	bag->key_size = 0;
	bag->value = NULL;
	bag->value_size = 0;
	bag->split_index = 0;
	bag->pipe_flag = FALSE;
	bag->p_head = NULL;
	bag->split = NULL;
	return (bag);
}

void init_envp(t_parsing *bag, char **envp)
{
	int i;

	i = 0;
	while (envp[i] != NULL)
	{
		ft_lstadd_back_envp(bag, ft_env_lstnew(bag, envp[i]));
		i++;
	}
}

void	init_builtins(t_parsing *bag)
{
	bag->builtins = malloc(sizeof (char *) * 8);
	if (!bag->builtins)
		ft_error(MEMORY, bag);
	bag->builtins[0] = "echo";
	bag->builtins[1] = "cd";
	bag->builtins[2] = "pwd";
	bag->builtins[3] = "export";
	bag->builtins[4] = "unset";
	bag->builtins[5] = "env";
	bag->builtins[6] = "exit";
	bag->builtins[7] = NULL;
}
