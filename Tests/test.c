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


void parent_process(int *comm);

typedef struct list{
	char *cmd;
	char **args;
	struct list *next;
} list;


void init_cmds(list **head);

void child_process(list *head, int *pipefd, int flag, char **envp);

int main(int argc,char **argv,  char **envp)
{
	list *head;
	int		pipefd[2];
	int exit_status;

	init_cmds(&head);
	pipe(pipefd);
	child_process(head, pipefd, 0, envp);
	child_process(head, pipefd, 1, envp);
	return 0;
}

void child_process(list *head, int *pipefd, int flag, char **envp)
{
	pid_t	pid;

	pid = fork();

	if (pid == 0)
	{

		if (!flag)
		{
			close(pipefd[0]);
			dup2(pipefd[1], STDOUT_FILENO);
			execve(head->cmd, head->args, envp);
		}
		if (flag)
		{
			dup2(STDOUT_FILENO, 1);
			close(pipefd[1]);
			dup2(pipefd[0], STDIN_FILENO);
			execve(head->next->cmd, head->next->args, envp);
		}
	}
}

void init_cmds(list **head)
{
	*head = malloc(sizeof (list));
	(*head)->cmd = "/bin/ls";
	(*head)->args = malloc(sizeof (char *) * 3);
	(*head)->args[0] = "/bin/ls";
	(*head)->args[1] = "-la";
	(*head)->args[2] = NULL;
	(*head)->next = malloc(sizeof (list));
	(*head)->next->cmd = "/usr/bin/grep";
	(*head)->next->args = malloc(sizeof (char *) * 3);
	(*head)->next->args[0] = "/usr/bin/grep";
	(*head)->next->args[1] = "test";
	(*head)->next->args[2] = NULL;
}