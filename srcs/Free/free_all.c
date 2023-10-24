#include "minishell.h"

void free_all(t_parsing *bag)
{
	if (bag->input)
	{
		bag->input = NULL;
		free(bag->input);
	}
	if (bag->p_head)
	{
		free_p(bag->p_head);
		bag->p_head = NULL;
	}
	if (bag->t_head)
	{
		free_t(bag->t_head);
		bag->t_head = NULL;
	}
}

void free_env(t_parsing *bag)
{
	t_list_env	*tmp;

	tmp = bag->env_head;
	while (tmp)
	{
		bag->env_head = bag->env_head->next;
		free(tmp->key);
		free(tmp->key);
		tmp = bag->env_head;
	}
}

void free_a(t_list_arg *head)
{
	t_list_arg *tmp;

	tmp = head;
	while (head)
	{
		head = head->next;
		free(tmp->arg);
		free(tmp);
		tmp = head;
	}
}

void free_t(t_list_tokken *head)
{
	t_list_tokken *tmp;

	tmp = head;
	while (tmp)
	{
		head = head->next;
		free_a(tmp->a_head);
		free(tmp->cmd);
		free(tmp);
		tmp = head;
	}
}

void free_p(t_list_pre *head)
{
	t_list_pre *tmp;

	tmp = head;
	while (head)
	{
		head = head->next;
		free(tmp->pre_tokken);
		free(tmp);
		tmp = NULL;
		tmp = head;
	}
}