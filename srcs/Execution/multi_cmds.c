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
	t_pipes			*pipes;
	int				exit_status;
	int				i;

	i = -1;
	pipes = NULL;
	pipes = open_pipes(bag, pipes);
	first_pipe(bag, envp, pipes);
	while (++i < bag->nmbr_cmds - 2)
		mid_pipes(bag, envp, pipes, i);
	final_pipe(bag, envp, pipes, i);
	i = 0;
	while (i < bag->nmbr_cmds)
		waitpid(pipes->pid[i++], &exit_status, 0);
	free_pipes(pipes, bag);
	handle_exit_status(exit_status);
}

void	free_pipes(t_pipes *pipes, t_parsing *bag)
{
	int	i;

	i = 0;
	while (i < bag->nmbr_cmds - 1)
		free (pipes->fd_pipes[i++]);
	free (pipes->pid);
	free (pipes);
}

//check output
void	final_pipe(t_parsing *bag, char **envp, t_pipes *pipes, int i)
{
	if (i && pipe(pipes->fd_pipes[i]) != 0)
		exit(1);
	pipes->pid[i] = fork();
	if (pipes->pid[i] < 0)
		exit(1);
	if (pipes->pid[i] == 0)
	{
		close(pipes->fd_pipes[i][1]);
		dup2(pipes->fd_pipes[i][0], STDIN_FILENO);
		close(pipes->fd_pipes[i][0]);
		if (bag->t_head->builtin_id != NO_BUILTIN)
			ft_execute_builtin(bag->t_head, bag);
		else
			ft_execute(bag, bag->t_head, envp);
	}
	if (bag->t_head->hrdoc)
		write(STDIN_FILENO, bag->t_head->hrdoc, ft_strlen(bag->t_head->hrdoc));
	close(pipes->fd_pipes[i][0]);
	close(pipes->fd_pipes[i][1]);
}

void	mid_pipes(t_parsing *bag, char **envp, t_pipes *pipes, int i)
{
	if (pipe(pipes->fd_pipes[i]) != 0)
		exit(1);
	pipes->pid[i] = fork();
	if (pipes->pid[i] < 0)
		exit(1);
	if (pipes->pid[i] == 0)
	{
		close(pipes->fd_pipes[i][1]);
		dup2(pipes->fd_pipes[i][0], STDIN_FILENO);
		close(pipes->fd_pipes[i][0]);
		dup2(pipes->fd_pipes[i + 1][1], STDOUT_FILENO);
		close(pipes->fd_pipes[i + 1][1]);
		close(pipes->fd_pipes[i + 1][0]);
		if (bag->t_head->builtin_id != NO_BUILTIN)
			ft_execute_builtin(bag->t_head, bag);
		else
			ft_execute(bag, bag->t_head, envp);
	}
	close(pipes->fd_pipes[i][0]);
	close(pipes->fd_pipes[i][1]);
	if (bag->t_head->hrdoc)
		write(STDIN_FILENO, bag->t_head->hrdoc, ft_strlen(bag->t_head->hrdoc));
	bag->t_head = bag->t_head->next;
}

//check input
void	first_pipe(t_parsing *bag, char **envp, t_pipes *pipes)
{
	if (pipe(pipes->fd_pipes[0]) != 0)
		exit(1);
	pipes->pid[0] = fork();
	if (pipes->pid[0] < 0)
		exit(1);
	if (pipes->pid[0] == 0)
	{
		close(pipes->fd_pipes[0][0]);
		dup2(pipes->fd_pipes[0][1], STDOUT_FILENO);
		close(pipes->fd_pipes[0][1]);
		if (bag->t_head->builtin_id != NO_BUILTIN)
			ft_execute_builtin(bag->t_head, bag);
		else
			ft_execute(bag, bag->t_head, envp);
	}
	if (bag->t_head->hrdoc)
		write(STDIN_FILENO, bag->t_head->hrdoc, ft_strlen(bag->t_head->hrdoc));
	bag->t_head = bag->t_head->next;
}

t_pipes	*open_pipes(t_parsing *bag, t_pipes	*pipes)
{
	int	i;

	i = 0;
	pipes = malloc(sizeof (t_pipes));
	pipes->fd_pipes = malloc(sizeof (int *) * bag->nmbr_cmds);
	while (i < bag->nmbr_cmds - 1)
	{
		pipes->fd_pipes[i] = malloc(sizeof (int) * 2);
		if (!pipes->fd_pipes[i])
			ft_error(MALLOC, bag);
		i++;
	}
	pipes->pid = malloc(sizeof (pid_t) * bag->nmbr_cmds);
	if (!pipes->pid)
		ft_error(MALLOC, bag);
	return (pipes);
}

void	handle_exit_status(int exit_status)
{
	if (WIFEXITED(exit_status))
		g_status = WEXITSTATUS(exit_status);
}
