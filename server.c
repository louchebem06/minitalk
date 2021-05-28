/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:24:38 by bledda            #+#    #+#             */
/*   Updated: 2021/05/28 17:07:02 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handler(int seg)
{
	static int size = 0;
	static int charset = 0;
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
   	{
   		size++;
   	}
   	if (size == 8)
   	{
   		ft_printf("%c", charset);
   		size = 0;
   		charset = 0;
   	}
}

int	main(void)
{
	int PID;

	PID = getpid();
	ft_printf("PID: %d\n\n", PID);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while(1)
	{
		pause ();
	}
	return (0);
}