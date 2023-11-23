#include "minishell.h"


void ft_one_cmd(t_parsing *bag, char **envp)
{
	int		original_stdin;
	int		original_stdout;

	original_stdin = dup(STDIN_FILENO);
	original_stdout = dup(STDOUT_FILENO);
	if (bag->t_head->input >= 3)
		dup2(bag->t_head->input, STDIN_FILENO);
	if (bag->t_head->output >= 3)
		dup2(bag->t_head->output, STDOUT_FILENO);
	if (bag->t_head->builtin_id != NO_BUILTIN)
		g_status = ft_execute_builtin(bag->t_head, bag);
	else
		ft_execute(bag, bag->t_head, envp);
	if (bag->t_head->input >= 3)
		close(bag->t_head->input);
	if (bag->t_head->output >= 3)
		close(bag->t_head->output);
	dup2(original_stdin, STDIN_FILENO);
	dup2(original_stdout, STDOUT_FILENO);
	close(original_stdout);
	close(original_stdin);
}


//replace NULL by the option tro the builtin
void ft_execute(t_parsing *bag, t_list_tokken *current, char **envp)
{
	char	filepath[MAXPATHLEN];
	char	**splited_path;
	int		i;

	if (access(current->cmd, X_OK) == 0)
		execve(current->cmd, current->exec, envp);
	splited_path = ft_getsplitedpath(bag->env_head);
	i = 0;
	while (splited_path && splited_path[i] != NULL)
	{
		ft_strcpy(filepath, splited_path[i]);
		ft_strcat(filepath, "/");
		ft_strcat(filepath, current->cmd);
		if (access(filepath, X_OK) == 0)
		{
			execve(filepath, current->exec, envp);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (splited_path)
		ft_freesplit(splited_path);
	ft_putstr_fd(current->cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
	exit(127);
}