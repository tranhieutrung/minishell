/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:47:30 by ktieu             #+#    #+#             */
/*   Updated: 2024/09/22 20:28:38 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

//----------------------------------------------------
// REDIRECT 
//-----------------------------------------------------
void		ft_redirect_append(t_redirect **head, t_redirect *new_redirect);
void		ft_redirect_clear(t_redirect **head);
t_redirect	*ft_token_redirect(t_shell *shell, char **str, char op, int count);

//----------------------------------------------------
// OPERATOR 
//-----------------------------------------------------
int			ft_token_handle_op(char **ptr, t_shell *shell);

//----------------------------------------------------
// CMD 
//-----------------------------------------------------

char		*ft_token_join_cmd(t_token *token, char *str);

//----------------------------------------------------
// UTILS 
//-----------------------------------------------------
int			ft_token_realloc(t_shell *shell);
void		ft_token_free(t_shell *shell);

//----------------------------------------------------
// PRINT 
//-----------------------------------------------------
void		ft_token_print(t_shell *shell);
void		ft_redirect_print(t_redirect **head);

//----------------------------------------------------
// TOKEN 
//-----------------------------------------------------
int			tokenize(t_shell *shell, char *line);

#endif