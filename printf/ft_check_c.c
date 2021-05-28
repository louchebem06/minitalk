/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:18:16 by bledda            #+#    #+#             */
/*   Updated: 2021/04/20 16:22:01 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_c(char input, va_list args, int *flags, unsigned int *cmp)
{
	int				decimal;
	unsigned int	cmp2;

	cmp2 = 0;
	if (input == 'c')
	{
		decimal = va_arg(args, int);
		if (flags[2] == -1)
			ft_putchar_fd(decimal, 1);
		else
		{
			if (flags[0] == 0)
			{
				ft_putchar_fd(decimal, 1);
				ft_before_data(flags[2], 1, ' ', &cmp2);
			}
			else
			{	
				ft_before_data(flags[2], 1, ' ', &cmp2);
				ft_putchar_fd(decimal, 1);
			}
		}
		*cmp += cmp2 + 1;
	}
}
