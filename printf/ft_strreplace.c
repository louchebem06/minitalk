/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 17:41:29 by bledda            #+#    #+#             */
/*   Updated: 2021/04/21 13:18:33 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_size(char *mstr, char*rep)
{
	char	*str;

	if (rep[0] == 0)
		str = ft_calloc(sizeof(char), ft_strlen(mstr) + 2);
	else
		str = ft_calloc(sizeof(char), ft_strlen(mstr) + ft_strlen(rep) + 2);
	return (str);
}

void	ft_free(char *str, char *mstr, char *rep)
{
	free(str);
	free(mstr);
	free(rep);
}

char	*ft_strreplace(char *mstr, char charset, char *rep)
{
	char	*str;
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	if (ft_strchr(mstr, (int)charset) == 0)
		return (mstr);
	str = ft_size(mstr, rep);
	while (mstr[i] != charset)
	{
		str[i] = mstr[i];
		i++;
	}
	tmp = ft_strjoin(str, rep);
	j = ft_strlen(tmp);
	i++;
	while (mstr[i] != 0)
	{
		tmp[j] = mstr[i];
		i++;
		j++;
	}
	ft_free(str, mstr, rep);
	return (tmp);
}
