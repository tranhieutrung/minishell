/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:46:08 by ktieu             #+#    #+#             */
/*   Updated: 2024/11/05 00:31:09 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include <sys/wait.h>
typedef struct s_shell	t_shell;
#include <errno.h>

/**
 * Data structure for AST (Abstract Syntax Tree)
 */
typedef struct s_ast
{
	t_token			token;
	struct s_ast	*left;
	struct s_ast	*right;
}	t_ast;

//---------------------------------||   AST   ||------------------------------//
int	read_heredoc(t_token *tokens, int size);
t_ast	*build_ast(t_token *tokens);

//---------------------------------||EXECUTION||------------------------------//

void	execute_ast(t_shell *shell, t_ast *ast);
char	*find_command_path(char **envp, char *command);
void	execute_command(t_shell *shell, t_token token);

char	**split_command(char *command);
int	ft_is_all_white_spaces(char *s);
void	handle_cmd_error(char **command, char *message, int free_pt);
int	skip_quotes(char *str, int i);
int	skip_word(char *str, int i);
//---------------------------------||  UTILS  ||------------------------------//

// void	print_ast(t_ast *ast);
void	redirect_fd(int from_fd, int to_fd);
void	ft_free_triptr(char ***str);
void	create_pipe(int *pipe_id);
pid_t	init_child(t_shell *shell);
int		update_status(t_shell *shell, int new_status); //0111

//---------------------------------||  ERROR  ||------------------------------//

void	open_error(t_shell *shell, char *path, int *fd);
void 	exec_error(t_shell *shell, char *command_path);
void 	fork_error(t_shell *shell);

#endif