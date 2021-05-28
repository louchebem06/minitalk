/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:38:52 by bledda            #+#    #+#             */
/*   Updated: 2021/04/21 13:26:12 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_print_s(int *flags, char *str, size_t f, int flags_size)
{
	unsigned int	cmp;

	cmp = 0;
	if (flags[1] == -1 && flags[2] == -1)
		ft_putstr_fd(str, 1);
	else
	{
		if (flags[1] != -1)
		{
			if (ft_strlen(str) <= (size_t)flags[2])
				f = ft_strlen(str);
			else
				f = flags[2];
			flags_size = flags[1];
		}
		if (flags[0] != 0)
			ft_before_data(flags_size, (int)f, ' ', &cmp);
		ft_putnstr(str, (int)f);
		if (flags[0] == 0)
			ft_before_data(flags_size, (int)f, ' ', &cmp);
	}
	return (cmp + f);
}

void	ft_check_s(char input, va_list args, int *flags, unsigned int *cmp)
{
	char			*str;
	unsigned int	cmp2;
	size_t			f;
	int				flags_size;

	cmp2 = 0;
	flags_size = flags[2];
	if (input != 's')
		return ;
	str = va_arg(args, char *);
	if (str == 0)
		str = ft_strdup("(null)");
	f = ft_strlen(str);
	cmp2 = ft_print_s(flags, str, f, flags_size);
	if (ft_strncmp(str, "(null)", 6) == 0)
		free(str);
	*cmp += cmp2;
}
