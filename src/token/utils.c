/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:31:57 by ktieu             #+#    #+#             */
/*   Updated: 2024/09/22 19:35:16 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_token_join_cmd(t_token *token, char *str)
{
    char	*cmd;

    cmd = token->cmd;
    token->cmd = ft_strjoin_space(cmd, str);
    free(cmd);
    if (!token->cmd)
    {
        return (NULL);
    }
    return (token->cmd);
}
