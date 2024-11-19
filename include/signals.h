/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:08:06 by ktieu             #+#    #+#             */
/*   Updated: 2024/11/19 23:01:49 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

typedef struct s_shell	t_shell;

typedef enum e_signal_type
{
	PARENT,
	CHILD,
	HEREDOC
}	t_signal_type;

//---------------------------------||  SIGNAL ||------------------------------//

int		start_signal(t_shell *shell, t_signal_type type);

//---------------------------------||  UTILS  ||------------------------------//

int		event(void);
void	set_signal_exit(t_shell *shell);
void	sig_handler_heredoc(int signal_number);
void	sig_parent_handler(int signal_number);

#endif