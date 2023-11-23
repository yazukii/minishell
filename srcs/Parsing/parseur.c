#include "minishell.h"

void print_exec(t_list_tokken *test);

int	parseur(t_parsing *bag)
{
	expand(bag);
	clean_end_space(bag);
	pre_tokken(bag, bag->input);
	pre_tokken_size(bag);
	tokkenizer(bag);
	get_option(bag);
	print_exec(bag->t_head);
    return (0);
}

void print_exec(t_list_tokken *test)
{
	char **test1;
	int i;

	i = 0;
	test1 = test->exec;
	while (test1[i])
	{
		printf("%s\n", test1[i]);
		i++;
	}
}

void get_option(t_parsing *bag)
{
	t_list_tokken	*current;

	current = bag->t_head;
	while(current)
	{
		current->exec = fill_exec(current, bag);
		current = current->next;
	}
}

char **fill_exec(t_list_tokken *current, t_parsing *bag)
{	char		**ret;
	t_list_arg	*a_current;
	int			i;
	int			len;

	i = 1;
	if (current->a_head)
		a_current = current->a_head;
	len = ft_number_args(current);
	ret = malloc(sizeof (char *) * len + 2);
	if (!ret)
		ft_error(MEMORY, bag);
	ret[0] = ft_strdup(current->cmd);
	while (len)
	{
		ret[i++] = ft_strdup(a_current->arg);
		a_current = a_current->next;
		len--;
	}
	ret[i] = NULL;
	return (ret);
}

int ft_number_args(t_list_tokken *current)
{
	t_list_arg	*a_current;
	int			i;

	i = 0;
	a_current = current->a_head;
	while (a_current)
	{
		i++;
		a_current = a_current->next;
	}
	return (i);
}

void clean_end_space(t_parsing *bag)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;	j = 0;
	while (bag->input[i])
	{
		i++;
		j++;
	}
	i--;
	while (bag->input[i] == ' ')
		i--;
	if (i + 1 == j)
		return ;
	tmp = malloc(sizeof (char) * i + 2);
	if (!tmp)
		ft_error(MEMORY, bag);
	ft_strlcpy(tmp, bag->input, i + 2);
	free(bag->input);
	bag->input = tmp;
}

void	tokkenizer(t_parsing *bag)
{
	bag->can_exp = TRUE;
	bag->in_double = FALSE;
	bag->in_simple = FALSE;
	fill_tokkens_recursive(bag);
}

