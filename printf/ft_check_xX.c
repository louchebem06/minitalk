/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_xX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:55:58 by bledda            #+#    #+#             */
/*   Updated: 2021/04/22 17:11:56 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_xX(char input, va_list args, int *flags, unsigned int *cmp2)
{
	unsigned int		cmp;
	char				*str;
	unsigned long long	decimal;
	int					neg;

	neg = 0;
	if (input != 'x' && input != 'X')
		return ;
	decimal = va_arg(args, unsigned int);
	if (decimal == 0)
		str = ft_strdup("0");
	else
		str = ft_itoh(decimal);
	if (input == 'x')
		str = ft_strtolower(str);
	else
		str = ft_strtoupper(str);
	ft_flags_di(flags, &cmp, neg, str);
	free(str);
	*cmp2 += cmp;
}
