/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_di_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:35:37 by bledda            #+#    #+#             */
/*   Updated: 2021/04/22 13:01:41 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isneg_di(int neg, unsigned int *cmp)
{
	if (neg == 1)
	{
		ft_putchar_fd('-', 1);
		*cmp += 1;
		return (1);
	}
	return (0);
}

void	ft_just_print(int neg, unsigned int *cmp, char *str)
{
	ft_isneg_di(neg, cmp);
	ft_putstr_fd(str, 1);
	*cmp += ft_strlen(str);
}

void	ft_space_neg(size_t f, int flags, int neg, unsigned int *cmp)
{
	if ((int)f < flags)
	{
		if (neg == 0)
			ft_before_data(flags, f, ' ', cmp);
		else if (neg == 1)
			ft_before_data(flags, f + 1, ' ', cmp);
	}
}

void	ft_zero_neg(size_t f, int flags, int neg, unsigned int *cmp)
{
	if ((int)f < flags)
	{
		if (neg == 0)
			ft_before_data(flags, f, '0', cmp);
		else if (neg == 1)
			ft_before_data(flags, f + 1, '0', cmp);
	}
}

void	ft_print_and_f_size(size_t *f, char *str)
{
	*f = ft_strlen(str);
	ft_putstr_fd(str, 1);
}
