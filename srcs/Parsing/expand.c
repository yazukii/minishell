#include "minishell.h"

//pas check avec get_env
void	expand(t_parsing *sac)
{
	sac->index++;
	sac->value = getenv(sac->key);
	sac->value_size = ft_strlen(sac->value);
	sac->input = replace_key(sac, sac->key_size);
	if (!sac->input)
		ft_error(MEMORY, sac);
	sac->index = sac->index + sac->value_size;
	free(sac->key);
	sac->key_size = 0;
}

char	*replace_key(t_parsing *sac, int key_size)
{
	int		tmp_value;
	char	*cln;

	sac->i = -1;
	sac->j = 0;
	tmp_value = sac->value_size;
	cln = malloc(sizeof (char) * (ft_strlen(sac->input) - \
						key_size + sac->value_size));
	if (!cln)
		return (NULL);
	while (sac->input[++sac->i] != '$')
		cln[sac->i] = sac->input[sac->i];
	while (tmp_value--)
	{
		cln[sac->i + sac->j] = sac->value[sac->j];
		sac->j++;
	}
	while (sac->input[sac->i + key_size])
	{
		cln[sac->i + sac->j] = sac->input[sac->i + key_size];
		sac->i++;
	}
	free(sac->input);
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

// check_sep error avec les singlequotes dans les doublesquotes
// faut pas check avec getenv parcequ'on pas update directement les variables d'env
int	check_env(t_parsing *sac)
{
	if (sac->input[sac->index] != '$')
		return (0);
	while (check_sep(sac->input[sac->index + sac->key_size]))
		sac->key_size++;
	sac->key = ft_trim(&(sac->input[sac->index]), sac->key_size);
	if (!sac->key)
		ft_error(MEMORY, sac);
	if (!getenv(sac->key))
	{
		sac->key_size = 0;
		return (0);
	}
	else
		return (1);
}
