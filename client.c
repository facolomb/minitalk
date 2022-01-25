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
#include "minitalk.h"

int	*ft_converttobin(char str)
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
	return (a);
}

void	ft_sendsignal(int pid, int *message, int i)
{
	if (message[i] == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
}

void ft_managemessage(char	*str, int pid)
{
	int	i;
	int	*message;

	while (*str != '\0')
	{
		i = 0;
		message = ft_converttobin(*str);
		while (i <= 6)
		{
			ft_sendsignal(pid, message, i);
			i++ ;
			usleep(50);
		}
		str++;
	}
	free(message);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		ft_managemessage(str, pid);
	}
	else
	{
		ft_printf("Argument error");
	}
	return (0);
}
