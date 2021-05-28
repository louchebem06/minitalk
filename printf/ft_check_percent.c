/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:18:58 by bledda            #+#    #+#             */
/*   Updated: 2021/04/20 16:22:30 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_percent(char input, int *flags_value, unsigned int *cmp)
{
	unsigned int	cmp2;

	cmp2 = 0;
	if (input == '%')
	{
		if (flags_value[2] == -1)
			ft_putchar_fd('%', 1);
		else
		{
			if (flags_value[0] == 0)
			{
				ft_putchar_fd('%', 1);
				ft_before_data(flags_value[2], 1, ' ', &cmp2);
			}
			else
			{	
				ft_before_data(flags_value[2], 1, ' ', &cmp2);
				ft_putchar_fd('%', 1);
			}
		}
		*cmp += cmp2 + 1;
	}
}
