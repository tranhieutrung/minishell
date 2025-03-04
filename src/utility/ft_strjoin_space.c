/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:22:04 by ktieu             #+#    #+#             */
/*   Updated: 2024/11/07 21:25:13 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin_space(char const *s1, char const *s2)
{
	char	*res;
	char	*ptr_res;

	if (!s1 || !s2)
		return (0);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!res)
		return (NULL);
	ptr_res = res;
	while (*s1 != '\0')
	{
		*ptr_res++ = *s1++;
	}
	*ptr_res++ = ' ';
	while (*s2 != '\0')
	{
		*ptr_res ++ = *s2++;
	}
	*ptr_res = '\0';
	return (res);
}
