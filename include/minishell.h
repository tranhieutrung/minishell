/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:08:06 by ktieu             #+#    #+#             */
/*   Updated: 2024/09/15 09:07:25 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "../libft/libft.h"
#include "./types.h"
#include "../src/token/token.h"
#include "trung.h"

#define PROMPT "minishell> "

//----------------------------------------------------
// ENVP 
//-----------------------------------------------------

char	**envp_dup(char **envp);

//----------------------------------------------------
// SHELL 
//-----------------------------------------------------

int		shell_init(t_shell *shell, char **envp);
void	shell_cleanup(t_shell *shell);

//----------------------------------------------------
// UTILS 
//-----------------------------------------------------

void 	ft_exit(char *str, int exitcode);
int		ft_error_ret(
			char *str,
			t_shell *shell,
			t_err_type type,
			int return_code);
char	*ft_prompt(char *prefix);

#endif