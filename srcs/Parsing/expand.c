#include "minishell.h"

//pas check avec get_env
void	expand(t_parsing *bag)
{
	bag->index++;
	bag->value = get_env(bag->key, bag->envp);
	if (!bag->value)
		ft_error(ENVP, bag);
	bag->value_size = ft_strlen(bag->value);
	bag->input = replace_key(bag, bag->key_size);
	if (!bag->input)
		ft_error(MEMORY, bag);
	bag->index = bag->index + bag->value_size;
	free(bag->key);
	bag->key_size = 0;
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
		return (NULL);
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

char	*ft_trim(char const *str, int size_to_trim)
{
	int		i;
	char	*r_str;

	i = -1;
	r_str = malloc(sizeof(char) * size_to_trim + 1);
	if (!r_str)
		return (NULL);
	while (++i < size_to_trim)
		r_str[i] = str[i];
	r_str[i] = '\0';
	return (r_str);
}

int	check_sep(char c)
{
	char	*seps;

	seps = " \"\'\\\0$";
	while (*seps)
	{
		if (c == *seps)
			return (0);
		seps++;
	}
	return (1);
}

int	check_env(t_parsing *bag)
{
	int	i;
	
	i = 0;
	if (bag->input[bag->index] != '$')
		return (0);
	while (check_sep(bag->input[bag->index + bag->key_size]))
		bag->key_size++;
	bag->key = ft_trim(&(bag->input[bag->index]), bag->key_size);
	if (!bag->key)
		ft_error(MEMORY, bag);
	while (bag->envp[i])
	{
		if (bag->envp[i++] == bag->key)
		{
			bag->key_size = 0;
			return (TRUE);
		}
	}
	return (FALSE);
}
