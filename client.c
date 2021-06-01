/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:24:38 by bledda            #+#    #+#             */
/*   Updated: 2021/06/01 10:59:38 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char *ft_itobin8(int ascii)
{
	char *binaire;

	binaire = ft_calloc(sizeof(char), 9);
	if (ascii >= 128)
	{
		ascii -= 128;
		binaire[0] = '1';
	}
	else
		binaire[0] = '0';

	if (ascii >= 64)
	{
		ascii -= 64;
		binaire[1] = '1';
	}
	else
		binaire[1] = '0';

	if (ascii >= 32)
	{
		ascii -= 32;
		binaire[2] = '1';
	}
	else
		binaire[2] = '0';

	if (ascii >= 16)
	{
		ascii -= 16;
		binaire[3] = '1';
	}
	else
		binaire[3] = '0';

	if (ascii >= 8)
	{
		ascii -= 8;
		binaire[4] = '1';
	}
	else
		binaire[4] = '0';

	if (ascii >= 4)
	{
		ascii -= 4;
		binaire[5] = '1';
	}
	else
		binaire[5] = '0';

	if (ascii >= 2)
	{
		ascii -= 2;
		binaire[6] = '1';
	}
	else
		binaire[6] = '0';

	if (ascii >= 1)
	{
		ascii -= 1;
		binaire[7] = '1';
	}
	else
		binaire[7] = '0';
	return (binaire);
}

int coucou = 0;

void	SEND(char *str_main, int PID_SERVEUR, int us)
{
	int i;
	int ascii;
	char *binaire;
	int j;
	char *str;

	i = 0;
	j = 0;
	str = ft_strjoin(str_main, "\n");
	while (str[i] != 0)
	{
		ascii = str[i];
		binaire = ft_itobin8(ascii);
		while (binaire[j] != 0)
		{
			coucou = 0;
			if (binaire[j] == '0')
				if (kill(PID_SERVEUR, SIGUSR2) == -1)
				{
					ft_printf("PID IS NOT FOUND\n");
					return ;
				}
			if (binaire[j] == '1')
				if (kill(PID_SERVEUR, SIGUSR1) == -1)
				{
					ft_printf("PID IS NOT FOUND\n");
					return ;
				}
			if (us != 1000)
			{
				while (coucou == 0)
				{
				}
				//pause();
				//usleep(us);
			}
			else
				usleep(us);
			j++;
		}
		ft_printf("%c", str[i]);
		j = 0;
		i++;
	}
}

void handler(int seg)
{
	//ft_printf("chien");
	coucou = 1;
	return ;
}

int	main(int ac, char **av)
{
	int PID_SERVEUR;

	signal(SIGUSR2, handler);
	if (ac == 3)
	{
		PID_SERVEUR = ft_atoi(av[1]);
		SEND(ft_itoa(getpid()), PID_SERVEUR, 1000);
		SEND(av[2], PID_SERVEUR, 100);
	}
	return (0);
}
