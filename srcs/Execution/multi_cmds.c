/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 23:07:55 by yidouiss          #+#    #+#             */
/*   Updated: 2023/11/23 23:07:55 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern volatile sig_atomic_t	g_status;

void	ft_multi_cmd(t_parsing *bag, char **envp)
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
			ft_run_cmd(bag, tmp, envp);
		}
		close_fds(tmp, &fd_pipe_read_tmp, fd_pipe);
		tmp = tmp->next;
	}
	while (waitpid(-1, &exit_status, 0) > 0)
		;
	handle_exit_status(exit_status);
}

void	ft_run_cmd(t_parsing *bag, t_list_tokken *cmd, char **envp)
{
	if (cmd->builtin_id != NO_BUILTIN)
		ft_execute(bag, cmd, envp);
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
