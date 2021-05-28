/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:10:20 by bledda            #+#    #+#             */
/*   Updated: 2021/04/21 12:06:46 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_print_p(int *flags, char *str)
{
	int				flags_size;
	size_t			f;
	unsigned int	cmp;

	cmp = 0;
	flags_size = flags[2];
	f = ft_strlen(str);
	if (flags[2] == -1 && flags[1] == -1)
		ft_putstr_fd(str, 1);
	else
	{
		if (flags[1] != -1)
		{
			if (ft_strlen(str) > (size_t)flags[2])
				f = flags[2];
			flags_size = flags[1];
		}
		if (flags[0] != 0)
			ft_before_data(flags_size, f, ' ', &cmp);
		ft_putnstr(str, f);
		if (flags[0] == 0)
			ft_before_data(flags_size, f, ' ', &cmp);
	}
	return (cmp + f);
}

void	ft_check_p(char input, va_list args, int *flags, unsigned int *cmp2)
{
	unsigned int		cmp;
	unsigned long long	decimal;
	char				*str;
	char				*tmp;

	cmp = 0;
	if (input != 'p')
		return ;
	decimal = va_arg(args, unsigned long long);
	str = ft_strtolower(ft_itoh(decimal));
	if (decimal == 0)
		tmp = ft_strdup("0x0");
	else
		tmp = ft_strjoin("0x", str);
	free(str);
	str = ft_strdup(tmp);
	free(tmp);
	cmp = ft_print_p(flags, str);
	free(str);
	*cmp2 += cmp;
}
