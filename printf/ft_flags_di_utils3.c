/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_di_utils3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:58:25 by bledda            #+#    #+#             */
/*   Updated: 2021/04/22 16:28:23 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_f_size(size_t *f, int flags, char *str)
{
	if ((int)ft_strlen(str) <= flags)
		*f = flags;
	else
		*f = ft_strlen(str);
}

int	ft_str_is_zero(char *str)
{
	if (ft_strncmp(str, "0", 1) != 0)
		ft_putstr_fd(str, 1);
	else
	{
		ft_putchar_fd(' ', 1);
		return (1);
	}
	return (0);
}

void	ft_print_zero_str_and_f_size(int flags, size_t *f, char *str)
{
	ft_before_data(flags, ft_strlen(str), '0', 0);
	ft_putstr_fd(str, 1);
	*f = flags;
}

void	ft_print_zero_str(int neg, unsigned int *cmp, int flags, char *str)
{
	size_t	f;

	f = ft_strlen(str);
	ft_isneg_di(neg, cmp);
	ft_zero_neg(f, flags, neg, cmp);
	ft_putstr_fd(str, 1);
}

int	ft_print_space_str(int neg, unsigned int *cmp, int flags, char *str)
{
	size_t	f;

	f = ft_strlen(str);
	ft_space_neg(f, flags, neg, cmp);
	ft_isneg_di(neg, cmp);
	ft_putstr_fd(str, 1);
	return (f);
}
