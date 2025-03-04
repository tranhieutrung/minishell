/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:19:14 by hitran            #+#    #+#             */
/*   Updated: 2024/12/17 13:26:41 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_array(char **array)
{
	int	index;

	index = 0;
	if (array)
	{
		while (array[index])
			free(array[index++]);
		free(array);
	}
}

int	array_length(char **array)
{
	int	len;

	len = 0;
	if (!array)
		return (0);
	while (array[len])
		len++;
	return (len);
}

void	ft_free_triptr(char ***str)
{
	int	i;

	i = 0;
	if (*str)
	{
		while ((*str)[i] != NULL)
			free((*str)[i++]);
		free(*str);
		*str = NULL;
	}
}
