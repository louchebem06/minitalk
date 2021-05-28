/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:55:51 by bledda            #+#    #+#             */
/*   Updated: 2021/04/22 16:29:18 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_u(char input, va_list args, int *flags, unsigned int *cmp2)
{
	unsigned int		cmp;
	int					neg;
	char				*str;
	unsigned long long	decimal;

	neg = 0;
	if (input != 'u')
		return ;
	decimal = va_arg(args, unsigned int);
	str = ft_uitoa(decimal);
	if (flags[2] == -1 && flags[1] == -1)
	{
		ft_isneg_di(neg, &cmp);
		ft_putstr_fd(str, 1);
		cmp += ft_strlen(str);
	}
	else
		ft_flags_di(flags, &cmp, neg, str);
	free(str);
	*cmp2 += cmp;
}
