#include "../headers/minishell.h"

/* we need to fork for each t_tokken
 * then use the pipe() to get the communication going
 * check if it's the last command to not creat a pipe
 * wait for all the previous commands to be executed
 * how to make it so that the previous cmd execution is the input for the next cmd?
 * */

void execution(t_parsing *bag)
{
	if (!bag->t_head)
		ft_error(INPUT, bag);
	if (!(bag->t_head->next))
		ft_one_cmd(bag);
	if (bag->t_head->next)
		ft_multi_cmd(bag);
}

void ft_multi_cmd(t_parsing *bag)
{
	t_list_tokken		*tmp;
	int					fd_pipe_read_tmp;
	int					fd_pipe[2];
	int					exit_status;
	pid_t				fork_pid;

	tmp = bag->t_head;
	fd_pipe_read_tmp = 0;
	while (tmp)
	{
		pipe(fd_pipe);
		fork_pid = fork();
		if (fork_pid == 0)
		{
			prepare_fds(tmp, &fd_pipe_read_tmp, fd_pipe);
			ft_run_cmd(bag, tmp);
		}
		close_fds(tmp, &fd_pipe_read_tmp, fd_pipe);
		tmp = tmp->next;
	}
	while (waitpid(-1, &exit_status, 0) > 0)
		;
	handle_exit_status(exit_status);
}

void ft_run_cmd(t_parsing *bag, t_list_tokken *cmd)
{
	if (cmd->builtin_id != NO_BUILTIN)
		ft_execute(bag, cmd);
	exit(ft_execute_builtin(cmd, bag));
}

void	handle_exit_status(int exit_status)
{
	if (WIFEXITED(exit_status))
		g_status = WEXITSTATUS(exit_status);
}

void	prepare_fds(t_list_tokken *cmd, int *fd_pipe_read_tmp, int *fd_pipe)
{
	close(fd_pipe[0]);
	if (cmd->input == 0)
		cmd->input = *fd_pipe_read_tmp;
	dup2(cmd->input, 0);
	if (cmd->output >= 3)
		close(fd_pipe[1]);
	else if (!cmd->next)
		cmd->output = 1;
	else
		cmd->output = fd_pipe[1];
	dup2(cmd->output, 1);
}

void	close_fds(t_list_tokken *cmd, int *fd_pipe_read_tmp, int *fd_pipe)
{
	close(fd_pipe[1]);
	if (*fd_pipe_read_tmp >= 3)
		close(*fd_pipe_read_tmp);
	if (cmd->output >= 3)
		close(cmd->output);
	if (cmd->input >= 3)
		close(cmd->input);
	*fd_pipe_read_tmp = fd_pipe[0];
}

int number_cmds(t_list_tokken *head)
{
	int				i;
	t_list_tokken	*current;

	i = 0;
	current = head;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}


