/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 10:39:41 by bledda            #+#    #+#             */
/*   Updated: 2021/06/01 15:14:31 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

char	*ft_strjoin(char const *s1, char s2)
{
	char	*strings;
	size_t	i;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = ft_strlen(s1) + 2;
	strings = ft_calloc(sizeof(char), i);
	i = 0;
	if (strings == 0)
		return (0);
	while (s1[i] != 0)
	{
		strings[i] = s1[i];
		i++;
	}
	strings[i] = s2;
	return (strings);
}
