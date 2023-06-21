/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:40:32 by yidouiss          #+#    #+#             */
/*   Updated: 2023/05/30 10:22:40 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

int main(int argc, char *argv[]) 
{
	char	*path = getenv("PATH");
	char	*dir;
	char	*dirs[256];
	int		i;
	int		j;
	char	exec_path[256];

	i = 0;
	j = 0;
	dir = strtok(path, ":");
	while (dir != NULL) 
	{
		dirs[i++] = dir;
		dir = strtok(NULL, ":");
	}

	while (j++ < i) 
	{
		strcpy(exec_path, dirs[j]);
		strcat(exec_path, "/");
		strcat(exec_path, argv[1]);
		if (access(exec_path, X_OK) == 0) 
		{
			execve(exec_path, argv + 1, NULL);
			fprintf(stderr, "Error: execve failed.\\n");
			exit(EXIT_FAILURE);
		}
	}
	fprintf(stderr, "Error: executable not found.\\n");
	exit(EXIT_FAILURE);
}


