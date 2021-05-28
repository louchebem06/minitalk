/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:55:43 by bledda            #+#    #+#             */
/*   Updated: 2021/04/21 19:44:48 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_di(char input, va_list args, int *flags, unsigned int *cmp2)
{
	unsigned int		cmp;
	int					neg;
	char				*str;
	unsigned long long	decimal;

	neg = 0;
	if (input != 'd' && input != 'i')
		return ;
	decimal = va_arg(args, int);
	if ((int)decimal < 0 && (int)decimal != -2147483648)
	{
		neg = 1;
		decimal *= -1;
	}
	str = ft_itoa(decimal);
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
