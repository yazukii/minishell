/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <jmorcom-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 03:32:14 by jmorcom-          #+#    #+#             */
/*   Updated: 2023/07/28 16:48:37 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>
#include <fcntl.h>

static int	read_line(int fd, char **cache, int count);

static int	read_line(int fd, char **cache, int count)
{
	char	buf[BUFFER_SIZE + 1];
	char	*old_cache;

	count = -2;
	while (count)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count == -1 || count == 0)
			return (count);
		buf[count] = '\0';
		if (*cache == NULL)
			*cache = ft_strdup(buf);
		else
		{
			old_cache = *cache;
			*cache = ft_strjoin(*cache, buf);
			free(old_cache);
		}
		if (ft_strchr(*cache, '\n'))
			break ;
	}
	return (count);
}

static int	get_line(char **res, char **cache, int fd, int *fd_status)
{
	if (!(*cache == NULL || !ft_strchr(*cache, '\n')))
		return (0);
	*res = NULL;
	*fd_status = read_line(fd, &(*cache), 0);
	if (*fd_status == 0)
	{
		if (*cache == NULL)
			return (1);
		*res = ft_strdup(*cache);
		free(*cache);
		*cache = NULL;
		return (2);
	}
	else if (*fd_status == -1)
	{
		free(*cache);
		*cache = NULL;
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*res;
	char		*end;
	char		*old_cache;
	int			fd_status;

	cache = NULL;
	if (get_line(&res, &cache, fd, &fd_status))
		return (res);
	if (ft_strchr(cache, '\n'))
	{
		res = ft_strdup(cache);
		end = ft_strchr(res, '\n') + 1;
		*end = '\0';
		old_cache = cache;
		cache = ft_strdup((ft_strchr(cache, '\n') + 1));
		free(old_cache);
		if (ft_strlen(cache) == 0)
		{
			free(cache);
			cache = NULL;
		}
		return (res);
	}
	return (NULL);
}
//
//char	*cut_str(char	*remain_str)
//{
//	int		i;
//	char	*r_str;
//
//	i = 0;
//	r_str = malloc(ft_size(remain_str) + 2);
//	if (!r_str)
//		return (NULL);
//	while (i < ft_size(remain_str))
//	{
//		r_str[i] = remain_str[i];
//		i++;
//	}
//	if (remain_str[i] == '\n')
//		r_str[i++] = '\n';
//	if (i <= ft_strlen_gnl(remain_str))
//		r_str[i] = 0;
//	return (r_str);
//}
//
//char	*clean_str(char	*remain_str)
//{
//	char	*cleaned_str;
//	int		i;
//
//	i = 0;
//	cleaned_str = malloc(ft_strlen_gnl(remain_str) - ft_size(remain_str) + 1);
//	if (!cleaned_str)
//		return (NULL);
//	while (i < ft_strlen_gnl(remain_str) - ft_size(remain_str))
//	{
//		cleaned_str[i] = remain_str[i + ft_strchr_gnl(remain_str) + 1];
//		i++;
//	}
//	free (remain_str);
//	if (cleaned_str[0] == 0)
//	{
//		free(cleaned_str);
//		return (NULL);
//	}
//	cleaned_str[i] = 0;
//	return (cleaned_str);
//}

/*
int	main(void)
{
	char *line;
	int i;
	int fd1;
	fd1 = open("test.txt", O_RDONLY);
	i = 1;
	while (i < 10)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
//	close(fd2);
//	close(fd3);
	return (0);
}
*/