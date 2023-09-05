//#include "minishell.h"
#include "unistd.h"

/*pour echo:
 * - faire des test
 * - print dans stdout
 * - identifier les sequences d'echapement
 * 		-\n, \t, \\, \", \$, \'
 * 	deja fait dans le parsing?
 * (- faire des substitutions de commandes
 * - ne pas print si le $txt est unset)
 *
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
	return ;
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
}
int main(int argc, char **argv)
{
	int i = 1;

	while (i < argc)
		echo(argv[i++], 0, 1);
	return (0);
}
