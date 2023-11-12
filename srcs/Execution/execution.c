#include "../headers/minishell.h"

int	argnum(t_list_arg *tmp)
{
	int num = 0;
	t_list_arg *arg = tmp;

	while (arg)
	{
		num++;
		arg = arg->next;
	}
	return (num);
}

void	tmp_arg(t_list_tokken *tokken)
{
	int 			i = 0;
	char			**ret;
	t_list_arg		*arg = tokken->a_head;

	ret = malloc(sizeof(char *) * argnum(arg));
	while (arg)
	{
		ret[i] = arg->arg;
		arg = arg->next;
		i++;
	}
	i = 0;
	tokken->args = ret;
}

void	tmp_parse(t_parsing bag, int st)
{
	t_list_tokken	*tokken = bag.t_head;

	if (st == 0)
	{
		while (tokken)
		{
			if (tokken->a_head)
				tmp_arg(tokken);
			else
				tokken->args = NULL;
			tokken = tokken->next;
		}
	}
}

void	tmpprnt(t_parsing *bag)
{
	t_list_tokken *tokken = bag->t_head;
	int i = 0;

	while (tokken)
	{
		printf("cmd: %s\n", tokken->cmd);
		if (tokken->args)
		{
			printf("args: ");
			while (tokken->args[i])
			{
				printf("%s, ", tokken->args[i]);
				i++;
			}
		}
		printf("\n\n");
		tokken = tokken->next;
	}
}

int execution(t_parsing *bag)
{
	t_list_tokken	*tmp;
	tmp = bag->t_head;
	tmp_parse(*bag, 0);
	tmpprnt(bag);
	while (tmp)
	{
		choose_builtin(bag);
		tmp = tmp->next;
	}
	return (0);
}

void	exec_cmd(t_parsing *bag)
{
	(void)bag;

	return ;
}