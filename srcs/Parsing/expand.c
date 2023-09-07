/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:50:46 by yidouiss          #+#    #+#             */
/*   Updated: 2023/08/08 18:42:34 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Returns the length the string would be after replacing the env var.
	This is done to be able to dinamically allocate memory later*/
int	var_length(char *str, int i)
{
	char	*var;
	int		j;
	int		size;

	i++;
	j = i;
	size = 0;
	while (str[j] != ' ' && str[j] != '\0' && str[j] != '\"')
		j++;
	var = malloc(sizeof(char) * (j - i));
	while (str[i] != ' ' && str[i] != '\0' && str[i] != '\"')
	{
		var[size] = str[i];
		size++;
		i++;
	}
	if (getenv(var) == 0)
		return (1);
	return (ft_strlen(getenv(var)) - (size - 1));
}

/*	When a '$' sign is found we call this function in order to get the value of
	the variable. The said value is returned as 'var'*/
char	*var_val(char *str, int i)
{
	char	*var;
	int		j;
	int		size;

	i++;
	j = i;
	size = 0;
	while (str[j] != ' ' && str[j] != '\0' && str[j] != '\"')
		j++;
	var = malloc(sizeof(char) * (j - i));
	while (str[i] != ' ' && str[i] != '\0' && str[i] != '\"')
	{
		var[size] = str[i];
		size++;
		i++;
	}
	return (getenv(var));
}

/*	Replace the name of the variable by it's value */
int	var_replace(int j, char *var, char **fstr)
{
	int		k;
	char	*tmp;

	k = 0;
	tmp = *fstr;
	while (var[k])
	{
		tmp[j] = var[k];
		k++;
		j++;
	}
	*fstr = tmp;
	return (j);
}

/*	Dynamically allocate the right amount of byte to the final str and then
	browse the string and whenever a var name is encountered, replace it
	by it's value with the function 'var_replace()' */
char	*var_alloc(char *str, int size)
{
	int		i;
	int		j;
	char	*fstr;
	char	*var;

	i = 0;
	j = 0;
	fstr = malloc(sizeof(char) * size);
	while (str[i])
	{
		if (!checksquotes(str[i], i) && str[i] == '$')
		{
			var = var_val(str, i);
			while (str[i] != ' ' && str[i] != '\0' && str[i] != '\"')
				i++;
			if (var)
				j = var_replace(j, var, &fstr);
			else
				i = j;
		}
		fstr[j++] = str[i++];
	}
	checksquotes(str[i], i);
	return (fstr);
}

/*	Get the size of the expanded string with the function var_length() and
	then call the function var_alloc() to actually expand the string */
void	expand(char **str)
{
	int		i;
//	char	*var;
	char	*tmp;
	int		strsize;

	i = 0;
	tmp = *str;
	strsize = 0;
	while (tmp[i])
	{
		if (tmp[i] == '$' && !checksquotes(tmp[i], i))
			strsize += var_length(tmp, i);
		else
			strsize++;
		i++;
	}
	checksquotes(tmp[i], -1);
	*str = var_alloc(tmp, strsize);
}
