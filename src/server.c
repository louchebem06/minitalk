/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:24:38 by bledda            #+#    #+#             */
/*   Updated: 2021/06/01 15:59:29 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

char	ft_decrypte(char charset, int *size, int seg)
{
	char	charset2;

	charset2 = charset;
	if (seg == SIGUSR1)
	{
		charset2 += 1 << *size;
		*size += 1;
	}
	else if (seg == SIGUSR2)
		*size += 1;
	return (charset2);
}

void	end(char charset, int *PIDN)
{
	ft_putchar_fd(charset, 1);
	if (charset == '\n')
	{
		kill(*PIDN, SIGUSR2);
		*PIDN = 0;
	}
}

void	handler(int seg)
{
	static int	size = 0;
	static char	charset = 0;
	static char	*PID;
	static int	PIDN = 0;

	charset = ft_decrypte(charset, &size, seg);
	if (size == 8)
	{
		if (PID == 0)
			PID = ft_calloc(sizeof(char), 1);
		if (charset != '\n' && PIDN == 0)
			PID = ft_strjoin(PID, charset);
		else if (charset == '\n' && PIDN == 0)
			PIDN = ft_atoi(PID);
		else if (PIDN != 0)
		{
			end(charset, &PIDN);
			if (charset == '\n')
				free(PID);
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
