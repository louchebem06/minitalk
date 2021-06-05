/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:24:38 by bledda            #+#    #+#             */
/*   Updated: 2021/06/05 17:08:35 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

void	handler(int sig)
{
	static int	size = 0;
	static char	charset = 0;

	if (sig == SIGUSR1)
	{
		charset += 1 << size;
		size += 1;
	}
	else if (sig == SIGUSR2)
		size += 1;
	if (size == 8)
	{
		ft_putchar_fd(charset, 1);
		size = 0;
		charset = 0;
	}
}

void	hand(int sig, siginfo_t *info, void *context)
{
	(void)context;
	handler(sig);
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sig;

	ft_putstr_fd("PID: ", 1);
	ft_putstr_fd(ft_itoa(getpid()), 1);
	ft_putchar_fd('\n', 1);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = hand;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
	{
	}
	return (0);
}
