/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:24:38 by bledda            #+#    #+#             */
/*   Updated: 2021/06/01 10:59:58 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handler(int seg)
{
	static int size = 0;
	static int charset = 0;
	static char *PID;
	static int PIDN = 0;
	char strc[2];

	if (seg == SIGUSR1)
	{
    	if (size == 0)
    		charset += 128;
    	else if (size == 1)
    		charset += 64;
    	else if (size == 2)
    		charset += 32;
    	else if (size == 3)
    		charset += 16;
    	else if (size == 4)
    		charset += 8;
    	else if (size == 5)
    		charset += 4;
    	else if (size == 6)
    		charset += 2;
    	else if (size == 7)
    		charset += 1;
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
   				PID = ft_calloc(1,1);
   			PID = ft_strjoin(PID, strc);
   		}
   		else if (charset == '\n' && PIDN == 0)
   		{
   			PIDN = ft_atoi(PID);
   			//ft_printf("%d\n", PIDN);
   			//kill(PIDN, SIGUSR2);
   		}
   		else if (PIDN != 0 && charset != '\n')
   		{
	   		ft_printf("%c", charset);
	   	}
	   	else if (PIDN != 0 && charset == '\n')
   		{
	   		ft_printf("%c", charset);
	   		kill(PIDN, SIGUSR2);
	   		PIDN = 0;
	   		free(PID);
	   	}
	   	size = 0;
   		charset = 0;
   	}

   	if (PIDN != 0)
   	{
   		//kill(PIDN, SIGUSR2);
   		if (kill(PIDN, SIGUSR2) == -1)
   			ft_printf("Error");
   		//else
   		//	ft_printf("Oui");
   		//usleep(10);
   	}
}

int	main(void)
{
	int PID;

	PID = getpid();
	ft_printf("PID: %d\n", PID);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while(1)
	{
	}
	return (0);
}