/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:30:16 by bledda            #+#    #+#             */
/*   Updated: 2021/04/21 12:46:30 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nb_char(unsigned int n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	char			*itoa;
	unsigned int	i;
	int				symbole;

	symbole = 0;
	if (n < 0)
	{
		n = -n;
		symbole++;
	}
	i = nb_char(n) + symbole;
	itoa = ft_calloc(sizeof(char), i + 1);
	if (itoa == 0)
		return (0);
	while (i > 0)
	{
		i--;
		itoa[i] = n % 10 + 48;
		n /= 10;
	}
	if (symbole == 1)
		itoa[i] = '-';
	return (itoa);
}
