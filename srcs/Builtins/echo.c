//#include "minishell.h"
#include "unistd.h"

/*pour echo:
 * - faire des test
 * - identifier les sequences d'echapement
 * 		-\n, \t, \\, \", \$, \'
 * 		- \n c'est un seul charactere en ascii?
 * 		- identifier le comportement si c'est juste un \ suivi d'un charactere
 *	- different comportement si les sequences d'echapement se trouvent entre double quote ou single
 *		- Double quotes allow variable expansion and interpretation of escape sequences.
		- Single quotes treat the enclosed text as a literal string, preserving it exactly as written without variable or escape sequence expansion.
*/
void	gestion_echapement(char *str, int i, int fd);
void	echo(char *str, int option_flag, int fd);

void	echo(char *str, int option_flag, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\\')
		{
			gestion_echapement(str, i, fd);
			i = i + 2;
		}
		else
			write(fd, &str[i++], 1);
	}
	if (!option_flag)
		write(fd, "\n", 1);
}

void	gestion_echapement(char *str, int i, int fd)
{
	if (str[i + 1] == 'n')
		write(fd, "\n", 1);
	if (str[i + 1] == '\\')
		write(fd, "\\", 1);
	if (str[i + 1] == 't')
		write(fd, "\t", 1);
	if (str[i + 1] == '"')
		write(fd, "\"", 1);
	if (str[i + 1] == '$')
		write(fd, "$", 1);
	if (str[i + 1] == '\'')
		write(fd, "\'", 1);
	else
		write(fd, &str[i], 1);
}
<<<<<<< HEAD
/*
=======

>>>>>>> main
int main(int argc, char **argv)
{
	int i = 1;

	while (i < argc)
		echo(argv[i++], 0, 1);
	return (0);
}*/
