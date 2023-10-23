#include "minishell.h"

//pas check avec get_env
int	expand(t_parsing *bag)
{
	bag->index++;
	bag->value = get_env(bag->key, &(bag->env_head));
	if (!bag->value)
		return(ft_error(ENVP, bag));
	bag->value_size = ft_strlen(bag->value);
	bag->input = replace_key(bag, bag->key_size);
	if (!bag->input)
		return(ft_error(MEMORY, bag));
	bag->index = bag->index + bag->value_size;
	free(bag->key);
	bag->key_size = 0;
    return (0);
}

char	*replace_key(t_parsing *bag, int key_size)
{
	int		tmp_value;
	char	*cln;

	bag->i = -1;
	bag->j = 0;
	tmp_value = bag->value_size;
	cln = malloc(sizeof (char) * (ft_strlen(bag->input) - \
						key_size + bag->value_size));
	if (!cln)
		ft_error(MEMORY, bag);
	while (bag->input[++bag->i] != '$')
		cln[bag->i] = bag->input[bag->i];
	while (tmp_value--)
	{
		cln[bag->i + bag->j] = bag->value[bag->j];
		bag->j++;
	}
	while (bag->input[bag->i + key_size])
	{
		cln[bag->i + bag->j] = bag->input[bag->i + key_size];
		bag->i++;
	}
	free(bag->input);
	return (cln);
}

char *ft_trim(char const *str, int size_to_trim, t_parsing *bag)
{
	int		i;
	char	*r_str;

	i = -1;
	r_str = malloc(sizeof(char) * size_to_trim);
	if (!r_str)
		ft_error(MEMORY, bag);
	while (++i < size_to_trim)
		r_str[i] = str[i + 1];
	r_str[i] = '\0';
	return (r_str);
}

int	check_sep(char c)
{
	char	*seps;
    int     i;

	seps = " \"\'\\\0$";
    i = 0;
	while (i < 6)
	{
		if (c == seps[i])
			return (0);
		i++;
	}
	return (1);
}

int	check_env(t_parsing *bag)
{
	t_list_env	*tmp;

	tmp = bag->env_head;
	if (bag->input[bag->index] != '$')
		return (FALSE);
    bag->key_size++;
	while (check_sep(bag->input[bag->index + bag->key_size]))
		bag->key_size++;
	bag->key = ft_trim(&(bag->input[bag->index]), bag->key_size, bag);
	if (!bag->key)
        return(ft_error(MEMORY, bag));
	while (tmp)
	{
		if (tmp->key == bag->key)
		{
			bag->key_size = 0;
			return (TRUE);
		}
		tmp = tmp->next;
	}
	return (FALSE);
}
