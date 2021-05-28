/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:01:58 by bledda            #+#    #+#             */
/*   Updated: 2021/04/16 14:15:20 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoh(unsigned long long nb)
{
	char				*itoh;
	int					i;
	unsigned long long	save_nb;
	char				*r;

	i = 0;
	itoh = ft_calloc(sizeof(char), 100);
	while (nb != 0)
	{
		save_nb = nb % 16;
		if (save_nb < 10)
			itoh[i++] = save_nb + 48;
		else
			itoh[i++] = save_nb + 55;
		nb /= 16;
	}
	ft_strrev(itoh);
	r = ft_strdup(itoh);
	free(itoh);
	return (r);
}
