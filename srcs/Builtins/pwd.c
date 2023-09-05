#include "minishell.h"

/* pwd:
 *		- getcwd
 *		- guestion d'erreur (set errno a quelque chose si on peut pas acceder le path)
 */

int	pwd(int fd)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * 1024);
	if (!str)
		return 2; //err
	str = getcwd(str, 1024);
	if (str)
	{
		while (str[i])
			write(fd, &str[i++], 1);
		free(str);
		return 1;
	}
	else
		return 0; //err
}

/*
int	main(void)
{
	pwd(1);
	return 0;
}*/