/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_di_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:37:17 by bledda            #+#    #+#             */
/*   Updated: 2021/04/22 17:04:49 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags_di_minus(unsigned int *cmp, int *flags, int neg, char *str)
{
	size_t			f;

	if (flags[0] != 0)
		return ;
	ft_isneg_di(neg, cmp);
	if (flags[1] == -1)
	{
		ft_print_and_f_size(&f, str);
		ft_space_neg(f, flags[2], neg, cmp);
	}
	else
	{
		if ((int)ft_strlen(str) >= flags[1] && (int)ft_strlen(str) >= flags[2])
			ft_print_and_f_size(&f, str);
		else
		{
			if ((int)ft_strlen(str) < flags[2])
				ft_print_zero_str_and_f_size(flags[2], &f, str);
			else
				ft_print_and_f_size(&f, str);
			ft_space_neg(f, flags[1], neg, cmp);
		}
	}
	*cmp += f;
}

void	ft_flags_di_clear(unsigned int *cmp, int *flags, int neg, char *str)
{
	size_t	f;

	if (flags[0] != 1)
		return ;
	f = 0;
	if (flags[1] == -1)
		f = ft_print_space_str(neg, cmp, flags[2], str);
	else
	{
		if ((int)ft_strlen(str) > flags[1] && (int)ft_strlen(str) > flags[2])
			ft_just_print(neg, cmp, str);
		else
		{
			ft_f_size(&f, flags[2], str);
			ft_print_zero_if(flags, str, f, cmp);
			ft_isneg_di(neg, cmp);
			ft_prt_zer_str_spc(flags, str, &f, cmp);
		}
	}
	*cmp += f;
}

void	ft_flags_di_zero(unsigned int *cmp, int *flags, int neg, char *str)
{
	size_t			f;

	if (flags[0] != 2)
		return ;
	f = ft_strlen(str);
	if (flags[1] == -1)
		ft_print_zero_str(neg, cmp, flags[2], str);
	else
	{
		if ((int)f >= flags[1] && (int)f >= flags[2])
		{
			ft_isneg_di(neg, cmp);
			ft_print_and_f_size(&f, str);
		}
		else
		{
			ft_f_size(&f, flags[2], str);
			ft_space_neg(f, flags[1], neg, cmp);
			ft_isneg_di(neg, cmp);
			ft_zero_or_str(&f, str, flags);
		}
	}
	*cmp += f;
}

void	ft_flags_di_zero_min(unsigned int *cmp, int *flags, int neg, char *str)
{
	size_t			f;

	if (flags[0] != 3)
		return ;
	ft_isneg_di(neg, cmp);
	if (flags[1] == -1)
	{
		ft_print_and_f_size(&f, str);
		ft_space_neg(f, flags[2], neg, cmp);
	}
	else
	{
		if ((int)ft_strlen(str) <= flags[2])
			ft_print_zero_str_and_f_size(flags[2], &f, str);
		else
			ft_str_is_zero(str);
		ft_f_size(&f, flags[2], str);
		ft_space_neg(f, flags[1], neg, cmp);
	}
	*cmp += f;
}

void	ft_flags_di(int *flags, unsigned int *cmp2, int neg, char *str)
{
	unsigned int	cmp;

	cmp = 0;
	if (!(flags[1] == 0) || !(flags[2] == 0))
	{
		ft_flags_di_minus(&cmp, flags, neg, str);
		ft_flags_di_clear(&cmp, flags, neg, str);
		ft_flags_di_zero(&cmp, flags, neg, str);
		ft_flags_di_zero_min(&cmp, flags, neg, str);
	}
	else if (ft_strncmp(str, "0", 1) != 0)
		ft_just_print(neg, &cmp, str);
	*cmp2 += cmp;
}
