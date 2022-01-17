/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:37:04 by facolomb          #+#    #+#             */
/*   Updated: 2022/01/10 13:37:04 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf/ft_printf.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int	*ft_convertToBin(char str)
{
	int		*a;
	int		i;

	i = 0;
	a = malloc(sizeof(int) * 7);
	while (str > 0)
	{
		a[i] = str % 2;
		str = str / 2;
		i++;
	}
	while (i <= 6)
	{
		a[i] = 0;
		i++;
	}
	return(a);
}

int	main(int argc, char **argv)
{
	int		pid;
	int		*message;
	int		i;
	char	*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		while (*str != '\0')
		{
			i = 0;
			message = ft_convertToBin(*str);
			while (i <= 6)
			{
				printf("bit : %d ", message[i]);
				if (message[i] == 1)
				{
					kill(pid, SIGUSR1);
					printf("sent : 1\n");
				}
				else
				{
						kill(pid,SIGUSR2);
					printf("sent : 0\n");
				}
				i++ ;
			}
			str++;
		}
	}
	return (0);
}