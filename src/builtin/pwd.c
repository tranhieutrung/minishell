/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:16:11 by hitran            #+#    #+#             */
/*   Updated: 2024/10/21 09:47:16 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_pwd()
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	printf("%s\n", cwd);
	free(cwd);
}
