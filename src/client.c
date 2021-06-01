/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:24:38 by bledda            #+#    #+#             */
/*   Updated: 2021/06/01 14:05:11 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

static int	g_pause = 0;

int	SEND_BYTE(int PID_SERVEUR, int size, char str, int us)
{
	while (++size < 8)
	{
		g_pause = 0;
		if ((str >> size) & 1)
		{
			if (kill(PID_SERVEUR, SIGUSR1) == -1)
				return (1);
		}
		else if (kill(PID_SERVEUR, SIGUSR2) == -1)
			return (1);
		if (us != 1000)
		{
			while (g_pause == 0)
			{
			}
		}
		else
			usleep(us);
	}
	return (0);
}

int	SEND(char *str_main, int PID_SERVEUR, int us)
{
	int		i;
	char	*str;
	int		size;

	i = -1;
	size = -1;
	str = ft_strjoin(str_main, "\n");
	while (str[++i] != 0)
	{
		if (SEND_BYTE(PID_SERVEUR, size, str[i], us))
			return (1);
	}
	return (0);
}

void	handler(int seg)
{
	(void)seg;
	g_pause = 1;
	return ;
}

int	main(int ac, char **av)
{
	int	PID_SERVEUR;

	signal(SIGUSR2, handler);
	if (ac == 3)
	{
		PID_SERVEUR = ft_atoi(av[1]);
		SEND(ft_itoa(getpid()), PID_SERVEUR, 1000);
		if (!SEND(av[2], PID_SERVEUR, 0))
			ft_putstr_fd("Msg is received\n", 1);
		else
			ft_putstr_fd("Error: server is not found\n", 1);
	}
	else if (ac < 3)
		ft_putstr_fd("Error: Not enough arguments\n", 1);
	else
		ft_putstr_fd("Error: Too many arguments\n", 1);
	return (0);
}
