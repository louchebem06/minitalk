/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:24:38 by bledda            #+#    #+#             */
/*   Updated: 2021/06/01 14:22:58 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

void	handler(int seg)
{
	static int	size = 0;
	static char	charset = 0;
	static char	*PID;
	static int	PIDN = 0;
	char		strc[2];

	if (seg == SIGUSR1)
	{
		charset += 1 << size;
		size++;
	}
	else if (seg == SIGUSR2)
		size++;
	if (size == 8)
	{
		strc[0] = charset;
		strc[1] = 0;
		if (charset != '\n' && PIDN == 0)
		{
			if (PID == 0)
				PID = ft_calloc(sizeof(char), 1);
			PID = ft_strjoin(PID, strc);
		}
		else if (charset == '\n' && PIDN == 0)
			PIDN = ft_atoi(PID);
		else if (PIDN != 0)
		{
			ft_putchar_fd(charset, 1);
			if (charset == '\n')
			{
				kill(PIDN, SIGUSR2);
				PIDN = 0;
				free(PID);
			}
		}
		size = 0;
		charset = 0;
	}
	if (PIDN != 0)
		kill(PIDN, SIGUSR2);
}

int	main(void)
{
	int	PID;

	PID = getpid();
	ft_putstr_fd("PID: ", 1);
	ft_putstr_fd(ft_itoa(PID), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
	{
	}
	return (0);
}
