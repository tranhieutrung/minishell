/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:53:50 by ktieu             #+#    #+#             */
/*   Updated: 2024/12/17 12:12:04 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	loop_cleanup(t_shell *shell)
{
	if (!shell)
		return ;
	if (shell->ast)
		ast_cleanup(&shell->ast);
	if (shell->tokens)
		ft_token_free(shell);
	shell->err_type = ERR_NONE;
}

static void	process_input(t_shell *shell, char **input, int size)
{
	if (!*input || !**input)
		return ;
	if (tokenize(shell, *input))
	{
		free(*input);
		*input = NULL;
		size = get_tokens_size(shell->tokens->array);
		if (!size)
			return ;
		if (!expansion(shell))
			return ;
		if (read_heredoc(shell, shell->tokens->array, size) == EXIT_FAILURE)
			return ;
		if (shell->err_type == ERR_SYNTAX)
			return ;
		if (!expansion_heredoc(shell))
			return ;
		shell->ast = build_ast(shell->tokens->array);
		if (!shell->ast)
			return ;
		execute_ast(shell, shell->ast);
	}
}

void	minishell(t_shell *shell)
{
	char	*input;

	while (!shell->aborted)
	{
		input = readline(PROMPT);
		if (!input)
			break ;
		if (ft_strcmp(input, ""))
		{
			add_history(input);
			process_input(shell, &input, 0);
			loop_cleanup(shell);
		}
		free(input);
	}
	rl_clear_history();
	return ;
}

int	main(int ac, char **av, char **envp)
{
	t_shell	shell;

	if (ac != 1)
	{
		ft_putendl_fd("Error: invalid number of arguments!\n", 2);
		exit (EXIT_FAILURE);
	}
	(void)av;
	shell_init(&shell, envp);
	if (!start_signal(&shell, PARENT))
		return (shell.exitcode);
	minishell(&shell);
	shell_cleanup(&shell);
	exit (shell.exitcode);
}
