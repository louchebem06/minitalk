/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_di_utils4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:57:35 by bledda            #+#    #+#             */
/*   Updated: 2021/04/22 17:05:41 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_zero_if(int *flags, char *str, size_t f, unsigned int *cmp)
{
	if ((int)f < flags[1] && ft_strncmp(str, "0", 1) != 0
		&& ft_strncmp(str, "1", 1) == 0)
		ft_before_data(flags[1], f + 1, ' ', cmp);
	else if ((int)f < flags[1] && ft_strncmp(str, "0", 1) != 0)
		ft_before_data(flags[1], f, ' ', cmp);
}

void	ft_prt_zer_str_spc(int *flags, char *str, size_t *f, unsigned int *cmp)
{
	size_t	tmp;

	tmp = *f;
	if ((int)tmp <= flags[2])
		ft_print_zero_str_and_f_size(flags[2], &tmp, str);
	else if (ft_strncmp(str, "0", 1) != 0)
		ft_putstr_fd(str, 1);
	else
	{
		ft_before_data(flags[1], 0, ' ', cmp);
		*cmp -= 1;
	}
	*f = tmp;
}

void	ft_zero_or_str(size_t *f, char *str, int *flags)
{
	size_t	tmp;

	tmp = *f;
	if ((int)tmp <= flags[2])
		ft_print_zero_str_and_f_size(flags[2], &tmp, str);
	else
		ft_str_is_zero(str);
	*f = tmp;
}
