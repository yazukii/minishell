/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:27:15 by yidouiss          #+#    #+#             */
/*   Updated: 2023/07/30 23:20:15 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	ft_cmdnum(char const *s, char c)
{
	int	n;
	int	i;
	int	sw;

	i = 0;
	n = 0;
	sw = 0;
	while (s[i])
	{
		if ((s[i] == '\"' || s[i] == '\'') && sw == 1)
			sw = 0;
		else if ((s[i] == '\"' || s[i] == '\'') && sw == 0)
			sw = 1;
		if (s[i] == c && sw == 0)
			n++;
		i++;
	}
	return (n + 1);
}

char	*createstr(char *str, int b, int e)
{
	char	*cmd;
	int		i;
	int		j;

	cmd = malloc(sizeof(char) * e - b + 1);
	i = b;
	j = 0;
	while (i < e)
	{
		cmd[j] = str[i];
		j++;
		i++;
	}
	cmd[j] = '\0';
	return (cmd);
}

int	checkquotes(char *str, int i)
{
	static int	sq;
	static int	dq;
	int			s;

	s = 0;
	if (i == -1)
	{
		if (sq == 1 || dq == 1)
			s = 1;
		sq = 0;
		dq = 0;
		return (s);
	}
	if (str[i] == '\'' && sq == 1)
		sq = 0;
	else if (str[i] == '\'' && sq == 0)
		sq = 1;
	if (str[i] == '\"' && dq == 1)
		dq = 0;
	else if (str[i] == '\"' && dq == 0)
		dq = 1;
	if (sq == 1 || dq == 1)
		return (1);
	else
		return (0);
}

char	**ft_cmdsplit(char *str, char s)
{
	t_split	sp;

	sp.j = 0;
	sp.i = -1;
	sp.b = 0;
	sp.e = 0;
	sp.cmd = malloc(sizeof(char *) * ft_cmdnum(str, s));
	while (str[++sp.i])
	{
		sp.sw = checkquotes(str, sp.i);
		if (str[sp.i] == s && sp.sw == 0)
		{
			sp.e++;
			if (str[sp.i + 1] != s)
			{
				sp.cmd[sp.j++] = createstr(str, sp.b, sp.i - (sp.e - 1));
				sp.b = sp.i + 1;
				sp.e = 0;
			}
		}
	}
	sp.cmd[sp.j] = createstr(str, sp.b, sp.i);
	if (checkquotes(str, -1) == 1)
		return (NULL);
	return (sp.cmd);
}
