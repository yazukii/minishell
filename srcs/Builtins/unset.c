#include "../../headers/minishell.h"

void env_delone(t_list_env *env)
{
	if (env == NULL || env->next == NULL)
		return; // Nothing to delete
	t_list_env *tmp = env->next;
	env->next = tmp->next;
	free(tmp);
}

void unset(t_parsing *bag)
{
	char *key = (bag->t_head)->a_head->arg;
	t_list_env *tmp = (*bag->env_head);

	while (tmp && tmp->next)
	{
		if (ft_strncmp(tmp->next->key, key, 1024) == 0)
		{
			env_delone(tmp);
			return;
		}
		tmp = tmp->next;
	}
}
