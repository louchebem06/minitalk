/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 20:53:45 by bledda            #+#    #+#             */
/*   Updated: 2021/04/19 20:58:04 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags(char *flags, char *input, int *a)
{
	int	f;
	int	i;

	f = 0;
	i = *a;
	ft_memset(flags, 0, ft_strlen(flags));
	while (ft_isconvert(input[i]))
		flags[f++] = input[i++];
	*a = i;
}
