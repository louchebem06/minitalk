/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:24:38 by bledda            #+#    #+#             */
/*   Updated: 2021/06/05 22:19:22 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

static int	g_pause = 0;

int	send_byte(int pid_server, char str)
{
	int size;

	size = 0;
	while (size < 8)
	{
		usleep(1);
		g_pause = 0;
		if ((str >> size) & 1)
		{
			if (kill(pid_server, SIGUSR1) == -1)
				return (1);
		}
		else if (kill(pid_server, SIGUSR2) == -1)
			return (1);
		while (g_pause == 0)
		{
		}
		size++;
	}
	return (0);
}

int	send(char *str_main, int pid_server)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strjoin(str_main, '\n');
	while (str[i] != 0)
	{
		if (send_byte(pid_server, str[i]))
			return (1);
		i++;
	}
	free(str);
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
	signal(SIGUSR2, handler);
	if (ac == 3)
	{
		if (!send(av[2], ft_atoi(av[1])))
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
