#include "minishell.h"

PLACE_HOLDERS:"path_to_file"

int	redirection_left(PLACE_HOLDER:"path_to_file")
{
	int	fd;

	fd = open("path_to_file", O_RDONLY);
	if (fd = -1)
		perror();
	return (fd);
}