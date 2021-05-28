/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:01:47 by bledda            #+#    #+#             */
/*   Updated: 2021/04/21 14:06:42 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_check(char input, va_list args, int *flags, unsigned int cmp)
{
	ft_check_c(input, args, flags, &cmp);
	ft_check_percent(input, flags, &cmp);
	ft_check_s(input, args, flags, &cmp);
	ft_check_p(input, args, flags, &cmp);
	ft_check_di(input, args, flags, &cmp);
	ft_check_u(input, args, flags, &cmp);
	ft_check_xX(input, args, flags, &cmp);
	return (cmp);
}

unsigned int	ft_gestion(char *input, va_list args, char *flags)
{
	int				i;
	unsigned int	cmp;
	int				flags_value[3];

	i = 0;
	cmp = 0;
	while (input[i] != 0)
	{
		if (input[i] == '%')
		{
			i++;
			ft_flags(flags, (char *)input, &i);
			ft_flagsjoin(flags_value, args, flags);
			cmp = ft_check(input[i], args, flags_value, cmp);
		}
		else
		{
			ft_putchar_fd(input[i], 1);
			cmp++;
		}
		i++;
	}
	return (cmp);
}

int	ft_printf(const char *input, ...)
{
	char			*flags;
	unsigned int	cmp;
	va_list			args;

	flags = ft_calloc(sizeof(char), ft_strlen(input));
	va_start(args, input);
	cmp = ft_gestion((char *)input, args, flags);
	free(flags);
	va_end(args);
	return (cmp);
}
