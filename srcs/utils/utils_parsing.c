#include "minishell.h"
/*
char	*get_env(const char *key, t_list_env **envp)
{
	if (!key)
        return(NULL);
	while (*envp)
	{
		if (ft_strcmp((*envp)->key, key, ft_strlen(key)))
            return ((*envp)->value);
		*envp = (*envp)->next;
	}
	return (NULL);
}*/

void debug_token(t_parsing *bag)
{
	t_list_tokken	*current;

	current = bag->t_head;
	while (current)
	{
		current = current->next;
	}
}

int	ft_strcmp(char const *str, char const *model, int size)
{
	int	i;

	i = 0;
	while (str[i] == model[i] && str[i] && model[i])
		i++;
	if (model[i] == '\0' && i == size)
		return (TRUE);
	return (FALSE);
}

void	pre_tokken_size(t_parsing *bag)
{
	t_list_pre	*current;
	int			i;

	i = 0;
	current = bag->p_head;
	while (current)
	{
		while (current->pre_tokken[i])
			i++;
		current->size = i;
		current = current->next;
		i = 0;
	}
}

bool	state_quote(t_parsing *bag, char c)
{
	if (c == '\"' && bag->in_double)
		bag->in_double = FALSE;
	else if (c == '\"' && !bag->in_double)
	{
		bag->in_double = TRUE;
		bag->can_exp = TRUE;
	}
	if (c == '\'' && bag->in_simple && !bag->in_double)
	{
		bag->in_simple = FALSE;
		bag->can_exp = TRUE;
	}
	else if (c == '\'' && !bag->in_simple && !bag->in_double)
	{
		bag->in_simple = TRUE;
		bag->can_exp = FALSE;
	}
	return (bag->can_exp);
}

