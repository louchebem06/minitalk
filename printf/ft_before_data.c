/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_before_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:20:56 by bledda            #+#    #+#             */
/*   Updated: 2021/04/21 16:38:22 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_before_data(int start, int size, char charset, unsigned int *cmp)
{
	char	*tmp;

	if (start >= 0)
	{
		tmp = ft_calloc(sizeof(char), start + 1);
		start -= size;
		if (start > 0)
		{
			tmp = ft_memset(tmp, charset, start);
			ft_putstr_fd(tmp, 1);
			if (cmp != 0)
				*cmp += start;
		}
		free(tmp);
		tmp = 0;
	}
}
