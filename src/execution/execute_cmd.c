/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:06:57 by hitran            #+#    #+#             */
/*   Updated: 2024/11/01 12:38:23 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	open_heredoc(char *heredoc)
{
	int	pipe_fd[2];

	create_pipe(pipe_fd);
	write(pipe_fd[1], heredoc, strlen(heredoc));
	close (pipe_fd[1]);
	return (pipe_fd[0]);
}

static void	redirect_io(t_shell *shell, t_redirect *redirect, int *fd)
{
	int	pipe_fd[2];

	while (redirect)
	{
		if (redirect->type == RD_HEREDOC)
			fd[0] = open_heredoc(redirect->path);
		else if (redirect->type == RD_IN)
			fd[0] = open(redirect->path, O_RDONLY);
		else if (redirect->type == RD_OUT)
			fd[1] = open(redirect->path, O_CREAT | O_RDWR | O_TRUNC, 0644);
		else if (redirect->type == RD_APPEND)
			fd[1] = open(redirect->path, O_CREAT | O_RDWR | O_APPEND, 0644);
		if (fd[0] == -1 || fd[1] == -1)
			open_error(shell, redirect->path, fd);
		redirect = redirect->next;
	}
	if (fd[0] != -2)
		redirect_fd(fd[0], STDIN_FILENO);
	if (fd[1] != -2)
		redirect_fd(fd[1], STDOUT_FILENO);
}

int	execute_builtin(t_shell *shell, char **token)
{
	if (!token || !token[0])
		return (0);
	if (!ft_strcmp(token[0], "echo"))
		return (builtin_echo(token));
	else if (!ft_strcmp(token[0], "cd"))
		return (builtin_cd(shell, token));
	else if (!ft_strcmp(token[0], "pwd"))
		return (builtin_pwd(shell));
	else if (!ft_strcmp(token[0], "export"))
		return (builtin_export(shell, token));
	else if (!ft_strcmp(token[0], "unset"))
		return (builtin_unset(shell, token));
	else if (!ft_strcmp(token[0], "env"))
		return (builtin_env(shell, token));
	else if (!ft_strcmp(token[0], "exit"))
		return (builtin_exit(shell, token));
	return (EXIT_FAILURE);
}

void	execute_command(t_shell *shell, t_token token)
{
	char	*command_path;
	pid_t	pid;
	int		fd[2];

	fd[0] = -2;
	fd[1] = -2;
	redirect_io(shell, token.redirect, fd);
	token.split_cmd = ft_split(token.cmd, ' ');
	if (!token.split_cmd)
		exit (EXIT_FAILURE);
	if(execute_builtin(shell, token.split_cmd) == EXIT_FAILURE)
	{
		pid = init_child(shell);
		if (pid == 0)
		{
			command_path = find_command_path(shell->envp, token.split_cmd[0]);
			execve(command_path, token.split_cmd, shell->envp);
			exec_error(shell, command_path);
		}
		waitpid(pid, NULL, 0);
	}
}
