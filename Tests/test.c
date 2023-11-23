#include "unistd.h"
#include "stdio.h"
# include <readline/readline.h>
# include <readline/history.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>

void child_process(int *comm);
void parent_process(int *comm);

int main(void)
{
	int		comm[2];
	pid_t	pid;

	pipe(comm);
	pid = fork();
	if (pid == -1)
		exit(1);
	else if (pid == 0)
		child_process(comm);
	else
		parent_process(comm);
	return 0;
}

void child_process(int *comm)
{
	close(comm[0]);
	write(comm[1], "test", 5);
}

void parent_process(int *comm)
{
	char *test;

	close(comm[1]);
	read(comm[0], test, 5);
	test[0] = '!';
	printf("%s", test);
}