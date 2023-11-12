#include "../../headers/minishell.h"

void	init_status()
{
	g_status.child_pid = -1;
	g_status.quit = 0;
}

t_parsing	*init_parseur(t_parsing *bag, char **envp, int flag)
{
	init_status();
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
	bag->has_expanded = FALSE;
	bag->heredoc_flag = FALSE;
	bag->first_cmd = TRUE;
	bag->key = NULL;
	bag->p_head = NULL;
	bag->t_head = NULL;
	return (bag);
}

void init_envp(t_parsing *bag, char **envp)
{
	int			i;
	t_list_env	*current;

	i = 0;
	while (envp[i] != NULL)
	{
		ft_lstadd_back_envp(bag, ft_env_lstnew(bag, envp[i]));
		i++;
	}
	current = bag->env_head;
	while (current)
	{
		(current)->k_size = ft_strlen((current)->key);
		(current)->v_size = ft_strlen((current)->value);
		(current) = (current)->next;
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
